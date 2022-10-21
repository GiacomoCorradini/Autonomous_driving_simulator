""" ---------------------------------------------------------------
Example: project a point from the 3D world onto a 2D image

Camera specification taken from CCD Sony IMX677-AAPH5 and HERO 09

A. Plebe 2022
--------------------------------------------------------------- """

import  numpy   as np
from    math    import sin, cos
from    PIL     import Image, ImageDraw, ImageColor


rho         = 1.12e-06          # pixel width and height (square pixels)
pixels      = ( 5700, 5160 )    # number of pixels ( W, H )
f_narrow    = 27e-03            # focal length of the "narrow field" option of HERO 09
f_linear    = 19e-03            # focal length of the "linear field" option of HERO 09
R_id        = np.eye( 4 )       # identity matrix (no rotation and no translation)

# Bounding box in the 3D world, orthogonal to the camera view
# first point is the upper left corner of the box
# second point is the lower right corner of the box
car_corners = (
        np.array( ( -1.5, 1.4, 40 ) ),
        np.array( (  3.0, 0.2, 40 ) )
)


def rotation( alpha=0.0, beta=0.0, theta=0.0 ):
    """
    Return a 3D rotation matrix (world -> camera)

    alpha   [float] camera rotation along X axis
    beta    [float] camera rotation along Y axis
    theta   [float] camera rotation along Z axis

    return  [numpy.ndarray] with shape ( 4, 4 )
    """
    R_x     = np.array( ( # rotation on the X axis
                (             1,                 0,                0,  0 ),
                (             0,      cos( alpha ),    -sin( alpha ),  0 ),
                (             0,      sin( alpha ),     cos( alpha ),  0 ),
                (             0,                 0,                0,  1 )
            ) )
    R_y     = np.array( ( # rotation on the Y axis
                (   cos( beta ),                 0,       sin( beta),  0 ),
                (             0,                 1,                0,  0 ),
                (  -sin( beta ),                 0,       cos( beta),  0 ),
                (             0,                 0,                0,  1 )
            ) )
    R_z     = np.array( ( # rotation on the Z axis
                (  cos( theta ),     -sin( theta ),                0,  0 ),
                (  sin( theta ),      cos( theta ),                0,  0 ),
                (             0,                 0,                1,  0 ),
                (             0,                 0,                0,  1 )
            ) )

    R       = np.matmul( R_x, np.matmul( R_y, R_z ) )
    # the final rotation matrix
    return R



def project( p, f=f_narrow, R=R_id, return_all=False ):
    """
    Project a 3D point onto pixel coordinates

    p       [numpy.ndarray] point in world space, with shape ( 3, )
    f       [float] optional focal length
    R       [numpy.ndarray] optional rotation (and translation) matrix, with shape ( 4, 4 )
    ret_all [bool] optionally, return all components

    return: [numpy.ndarray] with shape ( 2, )
    """

    w, h    = pixels
    t_u     = w / 2
    t_v     = h
    K_1     = np.array( (
                (  f,   0,  0,  0 ),
                (  0,   f,  0,  0 ),
                (  0,   0,  1,  0 )
            ) )
    K_2     = np.array( (
                ( 1 / rho,        0,    t_u ),
                (       0, -1 / rho,    t_v ),
                (       0,        0,    1   )
            ) )

    K       = np.matmul( K_2, K_1 )             # camera intrinsic matrix
    KQ      = np.matmul( K, R )                 # complete camera matrix
    P       = np.append( p, 1. )                # world point in homogeneous coordinates

    P       = np.matmul( KQ, P )                # apply the transformation to the point

    if return_all:
        return K_1, K_2, KQ, P

    p       = P[ : -1 ] / P[ -1 ]               # back to non-homogeneous coordinates
    return p.astype( int )                      # return the projected point as pixel



def draw_image( boxes, f ):
    """
    Draw an image with (any number of) bounding boxes

    boxes:          [list] [ ( ul, lr ), ... ] tuples with boundind boxes' coordinates
                                               (upper left and lower right corners)
    f:              [str] output filename
    """

    scale       = 10    # reduced size of output image

    # select automatically a new color to draw the next bounding box
    col_step    = 3
    col_names   = list( ImageColor.colormap.keys() )

    # the empty new image
    size        = ( pixels[ 0 ] // scale, pixels[ 1 ] // scale )
    img         = Image.new( 'RGB', size, color='black' )
    drw         = ImageDraw.Draw( img )

    # draw the bounding boxes
    for i, b in enumerate( boxes ):
        xy  = [ tuple( b[ 0 ] // scale ), tuple( b[ 1 ] // scale ) ]
        drw.rectangle( xy, fill=None, outline=col_names[ i * col_step ], width=2 )
    img.save( f )   # save the output image



if __name__ == '__main__':
    # bounding box projected without any rotation
    p1      = project( car_corners[ 0 ], f=f_linear )
    p2      = project( car_corners[ 1 ], f=f_linear )
    box1    = ( p1, p2 )
    boxes   = [ box1, ]
    draw_image( boxes, "img_01.jpg" )

    # bounding box projected with rotation on the X and Y axes
    rot_M   = rotation( alpha=-0.02, beta=0.04 )
    p1      = project( car_corners[ 0 ], R=rot_M, f=f_linear )
    p2      = project( car_corners[ 1 ], R=rot_M, f=f_linear )
    boxes.append( ( p1, p2 ) )
    draw_image( boxes, "img_02.jpg" )
