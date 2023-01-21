// Definisco la distanza minima tra due punti dell'albero
#define min_distance 10
int num_node = 0.0;

// Definisco una struct point
typedef struct
{
  double x;
  double y;
} point;

// Definisco una struct node per identificare un nodo come punto e costo
typedef struct node
{
  point p;
  struct node *parent;
} node;

// Definisco struct obstacle (rettangolo)
typedef struct
{
  double cx, cy; // Coordinate del centro dell'ostacolo
  double lx;     // Dimensioni lx/2
  double ly;     // Dimensioni ly/2
} obstacle;

// Funzione che verifica se il punto è sull'ostacolo
bool isObstacle(std::vector<double> &rvec_x, std::vector<double> &rvec_y, double cx, double cy, double lx, double ly, int point_retta, node extended)
{
  bool ret = false;

  // Controllo che nessun punto della retta sia sull'ostacolo
  for (int i = 0; i < point_retta; i++)
  {
    double x = rvec_x[i];
    double y = rvec_y[i];
    if (x >= cx - lx - 2 && x <= cx + lx + 2 && y >= cy - ly - 2 && y <= cy + ly + 2)
    {
      ret = true;
    }
  }

  // Controllo che il punto esteso non sia sull'ostacolo
  double x = extended.p.x;
  double y = extended.p.y;
  if (x >= cx - lx - 2 && x <= cx + lx + 2 && y >= cy - ly - 5 && y <= cy + ly + 5)
  {
    ret = true;
  }

  // Controllo che il punto esteso non vada oltre la carreggiata
  if (y > 37)
  {
    ret = true;
  }

  if (y < 0)
  {
    ret = true;
  }

  return ret;
}

// Funzione che calcola la distanza tra due punti
double distance(node random, node closest)
{
  double x1 = random.p.x;
  double y1 = random.p.y;
  double x2 = closest.p.x;
  double y2 = closest.p.y;
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Funzione per trovare il punto più vicino a x_new
int closest_node(double num_node, std::vector<node> &nodevec, node random)
{
  // minDistance è inizializzata come valore molto alto in modo che non possa essere miinore della possibile distanza tra due punti, perchè si andrebbe ad escludere a priori il punto in analisi.

  double minDistance = 1000;
  int closestPointIndex = -1;

  for (int i = 0; i < num_node; i++)
  {
    double d = distance(random, nodevec[i]);

    if (d < minDistance)
    {
      minDistance = d;
      closestPointIndex = i;
    }
  }
  return closestPointIndex;
}

// Funzione per individuare la retta tra due punti
void retta(node random, node closest, std::vector<double> &rvec_x, std::vector<double> &rvec_y, int point_retta, double m_retta, double b_retta)
{
  double x1 = random.p.x;
  double y1 = random.p.y;
  double x2 = closest.p.x;
  double y2 = closest.p.y;

  double m;

  if (x2 != x1)
  {
    m = (y2 - y1) / (x2 - x1); // Pendenza
  }
  else
  {
    m = 0; // Pendenza
  }

  double b = y1 - m * x1; // Intercetta b

  double interval = 0.1;

  double r_x[point_retta]; // Creo array di punti che formano la retta
  double r_y[point_retta]; // Creo array di punti che formano la retta

  // Calcola i valori di x e y per ogni punto sulla retta
  for (int i = 0; i < point_retta; i++)
  {
    double x = closest.p.x + i * interval;
    double y = m * x + b;

    rvec_x.push_back(x);
    rvec_y.push_back(y);

    m_retta = m;
    b_retta = b;
  }
}

// Funzione per estendere il nodo più vicino verso un punto casuale
node extend(node random, node closest)
{
  // Prendo il punto più vicino a quello random e lo estendo andando a creare l'albero tipico di un algoritmo RRT. La distanza minima del ramo è impostata a min_distance come variabile globale.

  double d = distance(random, closest);
  node ext;

  if (d != 0)
  {
    ext.p.x = closest.p.x + abs(random.p.x - closest.p.x) * min_distance / d;
    ext.p.y = closest.p.y + (random.p.y - closest.p.y) * min_distance / d;
  }
  else
  {
    ext = closest;
  }

  // La formula è: x = x1+(x2-x1)*(smax/dist), y = y1+(y2-y1)*(smax/dist)

  return ext;
}

double path_cost(std::vector<node> &nodevec, std::vector<node> &nodevec_par, int num_node, std::vector<node> &path)
{
  int i = num_node;
  double cost = 0.0;
  path.push_back(nodevec[i]);

  while (i != 0)
  {
    node last = nodevec[i];         // Vettore nodi
    node last_par = nodevec_par[i]; // Vettore parent dei nodi

    path.push_back(last_par);

    cost += distance(last, last_par);

    // A partire dall'ultimo punto del vettore, continuo a seguire il parent fino a che non raggiungo il punto di partenza, calcolando il costo come distanza percorsa.

    for (int j = 0; j < i; j++)
    {
      if ((nodevec[j].p.x == last_par.p.x) && (nodevec[j].p.y == last_par.p.y))
      {
        i = j;
      }
    }
  }

  return cost;
}

// FUNZIONE ALGORITMO RRT

void rrt_path(node start, node goal, obstacle obs, std::vector<node> &path_car)
{
  // Definisco un vettore di nodi che verrà aggiornato dall'algoritmo RRT*
  std::vector<node> nodevec;

  // Definisco un vettore che conterrà i parent dei nodi, avendo corrispondenza tra gli indici con il vettore dei nodi
  std::vector<node> nodevec_par;

  // Definisco il vettore con i punti del path finale
  std::vector<node> path;

  // Aggiungo il punto di partenza al vettore
  nodevec.push_back(start);
  nodevec_par.push_back(start);
  num_node++;

  srand(time(NULL));

  // INIZIO ALGORITMO RRT*

  while (1)
  {
    // printf("node %d\n", num_node);
    if (num_node > 15000)
    {
      printf("Path not find :(\n");
      break;
    }

    // Prendo un punto random
    node random;
    random.p.x = rand() % 1800; // Lunghezza strada * 10
    random.p.y = rand() % 40;   // Larghezza strada * 10

    // Prendo il punto dell'albero più vicino a quello random
    int index = closest_node(num_node, nodevec, random);
    node closest = nodevec[index];

    // Estendo il ramo nella direzione del punto random
    node extended = extend(random, closest);

    // Individuo la retta tra i due punti e genero un vettore per verificare se la retta interseca punti che sono ostacoli
    double interval = 0.1;
    int point_retta = (int)(abs(extended.p.x - closest.p.x) / interval) + 1;
    std::vector<double> rvecx;
    std::vector<double> rvecy;
    double m, b;
    retta(extended, closest, rvecx, rvecy, point_retta, m, b);
    int isobs = isObstacle(rvecx, rvecy, obs.cx, obs.cy, obs.lx, obs.ly, point_retta, extended);

    // Aggiungo un nuovo punto all'albero se non incontra ostacoli
    if (isobs != 1)
    {
      nodevec.push_back(extended);    // aggiungo nodo all'albero
      nodevec_par.push_back(closest); // aggiungo il parent del nodo

      // Termina algoritmo quando un punto dell'albero è a distanza d <= min_distance dal punto finale
      double d = distance(nodevec[num_node], goal);

      if (d <= min_distance)
      {
        printf("Punto finale = (%f, %f)\n", extended.p.x, extended.p.y);
        printf("Percorso trovato!\n");

        // Calcolo costo del percorso
        double cost = path_cost(nodevec, nodevec_par, num_node, path);
        int tot_nodes = (int)path.size();
        printf("Costo = %f\n", cost);
        printf("nodes = %d\n", tot_nodes);

        for (int i = 1; i <= tot_nodes; i++)
        {
          path_car.push_back(path[tot_nodes - i]);
          path_car[i - 1].p.x = (path_car[i - 1].p.x) / 10.0;
          path_car[i - 1].p.y = (path_car[i - 1].p.y) / 10.0;
        }

        FILE *file = fopen("path.csv", "w");

        // // Stampo i punti del path da seguire
        // for (int i = 0; i < tot_nodes; i++)
        // {
        //   printf("node %d = (%f, %f)\n", i, path_car[i].p.x, path_car[i].p.y);
        //   fprintf(file, "%f, %f\n", path_car[i].p.x, path_car[i].p.y);
        // }

        fclose(file);

        break;
      }

      num_node++;
    }
  }
}