#include "VAO.cpp"
#include "texture.cpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

using namespace glm;
GLFWwindow* window;

int main() {
    // Initialiser les donnees
    loadVAO(vertices);
    loadCouleur();
    for (int i = 0; i < 82 ; ++i) {
        cout << i << '\t'
             << couleur1[i*3] << '\t'
             << couleur1[i*3+1] << '\t'
             << couleur1[i*3+2] << endl;
    }
    for (int i = 0; i < 41 ; ++i) {
        cout << vertices[0][i*3] << '\t';
        cout << vertices[0][i*3+1] << '\t';
        cout << vertices[0][i*3+2] << '\t';
        cout << endl;
    }
    cout << endl;
    for (int k = 0; k < pts[0].size() ; ++k) {
        cout << k+1 << '\t';
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < pts.size() ; ++i) {
        for (int j = 0; j < pts[0].size() ; ++j) {
            cout
            << ranks[i][j] << '\t';
            //<< pts[i][j] << '\t';
        }
        cout << endl;
    }
    // Initiation des bases
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialiser le windows
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Demo", NULL, NULL);
    if (window == NULL)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.5f, 0.5f, 0.0f);

    /*
    GLuint programID = LoadShaders(
            "shader/demo.vertexshader",
            "shader/demo.fragmentshader" );

    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(couleur), couleur, GL_STATIC_DRAW);
    */
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT );
    // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION );
    // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( );
    // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 );
    // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW );
    // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( );

    // Dans le windows
    do{
        // Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );

        // Dessiner
        for (int j = 0; j < 4 ; ++j) {
            glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
            glEnableClientState( GL_COLOR_ARRAY );
            glVertexPointer( 3, GL_FLOAT, 0, vertices[j] ); // point to the vertices to be used
            glColorPointer( 3, GL_FLOAT, 0, couleur1 );
            glDrawArrays( GL_TRIANGLE_STRIP, 0, 82 ); // draw the vertices
            glDisableClientState( GL_COLOR_ARRAY );
            glDisableClientState( GL_VERTEX_ARRAY );
        }
        glDisableClientState( GL_COLOR_ARRAY );
        for (int i = 4; i < 7 ; ++i) {
            glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
            glEnableClientState( GL_COLOR_ARRAY );
            glVertexPointer( 3, GL_FLOAT, 0, vertices[i] ); // point to the vertices to be used
            glColorPointer( 3, GL_FLOAT, 0, couleur2 );
            glDrawArrays( GL_TRIANGLE_STRIP, 0, 82 ); // draw the vertices
            glDisableClientState( GL_COLOR_ARRAY );
            glDisableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're finished using the vertex arrayattribute
        }

        for (int i = 7; i < 11 ; ++i) {
            glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
            glEnableClientState( GL_COLOR_ARRAY );
            glVertexPointer( 3, GL_FLOAT, 0, vertices[i] ); // point to the vertices to be used
            glColorPointer( 3, GL_FLOAT, 0, couleur3 );
            glDrawArrays( GL_QUAD_STRIP, 0, 82 ); // draw the vertices
            glDisableClientState( GL_COLOR_ARRAY );
            glDisableClientState( GL_VERTEX_ARRAY );
        }

        for (int j = 11; j < 20 ; ++j) {
            glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
            glVertexPointer( 3, GL_FLOAT, 0, vertices[j] ); // point to the vertices to be used
            glDrawArrays( GL_QUAD_STRIP, 0, 82 ); // draw the vertices
            glDisableClientState( GL_VERTEX_ARRAY );
        }

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    return 0;

}