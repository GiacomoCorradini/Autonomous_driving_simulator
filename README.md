# Autonomous driving simulator

**Compile agent communication library**

   1) enter inside the folder agent_communication_lib
```
      $ cd agent_communication_lib
```
   2) compile the project with cmake (need ruby)
```
      $ cmake -Bbuild
      $ cmake --build build -t install
```
   3) copy file in bin/lib/libagent_lib.so into ../PyDrivingSim/agent
   4) copy file in bin/lib_static/libagent_lib.a into ../basic_agent_st/lib

**Compile Clothoids library**

   1) enter inside the folder Clothoids
```
      $ cd basic_agent/Clothoids
```
   2) compile the project with cmake
```
      $ cmake -Bbuild
      $ cmake --build build -t install
```

**Compile and run basic_agent**

   1) enter inside the folder basic_agent
```
      $ cd basic_agent
```
   2) compile the project with cmake
```   
      $ cmake -Bbuild
      $ cmake --build build
```
   3) run from terminal
```
      $ ./bin/basic_agent
```

**Run pydriving simulator**

   1) enter inside the folder PyDrivingSim
```
      $ cd PyDrivingSim
```
   2) run from terminal
```
      $ python3 simulator.py
```