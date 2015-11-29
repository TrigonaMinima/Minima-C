# include <iostream>
# include <ctime>
# include <time.h>
# include <GL/glut.h>
# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>


using namespace std;

// Define our initial screen width, height, and colour depth
GLint SCREEN_WIDTH = 800;
GLint SCREEN_HEIGHT = 600;
GLint SCREEN_BPP = 32;

// Define our SDL surface
SDL_Surface *surface;

// Number of fireworks
const int FIREWORKS = 10;
// Number of particles per firework
const int FIREWORK_PARTICLES = 50;


class Firework
{
public:
    GLfloat x[FIREWORK_PARTICLES];
    GLfloat y[FIREWORK_PARTICLES];

    GLfloat xSpeed[FIREWORK_PARTICLES];
    GLfloat ySpeed[FIREWORK_PARTICLES];
    static const GLfloat baselineYSpeed;
    static const GLfloat maxYSpeed;
    static const GLfloat GRAVITY;

    GLint framesUntilLaunch;
    GLfloat red, blue, green, alpha;
    GLfloat particleSize;

    GLboolean hasExploded;

    Firework()
    {
        initialise();
    }

    void initialise();
    void move();
    void explode();
};

const GLfloat Firework::baselineYSpeed = -4.0f;
const GLfloat Firework::maxYSpeed = -4.0f;
const GLfloat Firework::GRAVITY = 0.05f;


void Firework::initialise()
{
    // Pick an initial x location and  random x/y speeds
    float xLoc = (rand() / (float)RAND_MAX) * SCREEN_WIDTH;
    float xSpeedVal = -2 + (rand() / (float)RAND_MAX) * 4.0f;
    float ySpeedVal = baselineYSpeed + ((float)rand() / (float)RAND_MAX) * maxYSpeed;

    // Set initial x/y location and speeds
    for (int loop = 0; loop < FIREWORK_PARTICLES; loop++)
    {
        x[loop] = xLoc;
        y[loop] = SCREEN_HEIGHT + 10.0f; // Push the particle location down off the bottom of the screen
        xSpeed[loop] = xSpeedVal;
        ySpeed[loop] = ySpeedVal;
    }

    // Assign a random colour and full alpha (i.e. particle is completely opaque)
    red   = (rand() / (float)RAND_MAX);
    green = (rand() / (float)RAND_MAX);
    blue  = (rand() / (float)RAND_MAX);
    alpha = 1.0f;

    // Firework will launch after a random amount of frames between 0 and 400
    framesUntilLaunch = ((int)rand() % 400);

    // Size of the particle (as thrown to glPointSize) - range is 1.0f to 4.0f
    particleSize = 1.0f + ((float)rand() / (float)RAND_MAX) * 3.0f;

    // Flag to keep trackof whether the firework has exploded or not
    hasExploded = false;

    cout << "Initialised a firework." << endl;
}

void Firework::move()
{
    for (int loop = 0; loop < FIREWORK_PARTICLES; loop++)
    {
        // Once the firework is ready to launch start moving the particles
        if (framesUntilLaunch <= 0)
        {
            x[loop] += xSpeed[loop];
            y[loop] += ySpeed[loop];
            ySpeed[loop] += Firework::GRAVITY;
        }
    }
    framesUntilLaunch--;

    // Once a firework's speed turns positive (i.e. at top of arc) - blow it up!
    if (ySpeed[0] > 1.0f)
    {
        for (int loop2 = 0; loop2 < FIREWORK_PARTICLES; loop2++)
        {
            // Set a random x and y speed between -4 and + 4
            xSpeed[loop2] = -4 + (rand() / (float)RAND_MAX) * 8;
            ySpeed[loop2] = -4 + (rand() / (float)RAND_MAX) * 8;
        }

        cout << "Boom!" << endl;
        hasExploded = true;
    }
}

void Firework::explode()
{
    for (int loop = 0; loop < FIREWORK_PARTICLES; loop++)
    {
        // Dampen the horizontal speed by 1% per frame
        xSpeed[loop] *= 0.99;

        // Move the particle
        x[loop] += xSpeed[loop];
        y[loop] += ySpeed[loop];

        // Apply gravity to the particle's speed
        ySpeed[loop] += Firework::GRAVITY;
    }

    // Fade out the particles (alpha is stored per firework, not per particle)
    if (alpha > 0.0f)
        alpha -= 0.01f;
    else // Once the alpha hits zero reset the firework
        initialise();
}

// Create our array of fireworks
Firework fw[FIREWORKS];

// Function to release/destroy our resources and exit
int quit(int returnCode)
{
    // Clean up the window
    SDL_Quit();
    exit(returnCode);
}


void setupScreen(int& videoFlags)
{
    const SDL_VideoInfo *videoInfo;

    // Initialise SDL - quit out if we fail
    // if (SDL_Init(SDL_INIT_VIDEO) < 0)
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cerr << "Video initialization failed :" << SDL_GetError() << endl;
        quit(1);
    }

    // Get our video information
    videoInfo = SDL_GetVideoInfo();
    if (!videoInfo)
    {
        cerr << "Video query failed: " << SDL_GetError() << endl;
        quit(1);
    }

    // Setup our SDL to use OpenGL with double buffering, a hardware palette and enable window resizing
    videoFlags  = SDL_OPENGL;   // Enable OpenGL in SDL
    videoFlags |= SDL_GL_DOUBLEBUFFER;  // Enable double buffering
    videoFlags |= SDL_HWPALETTE;    // Store the palette in hardware
    videoFlags |= SDL_RESIZABLE;    // Enable window resizing

    // Check if our SDL surfaces can be stored in hardware memory or not
    if (videoInfo->hw_available)
        videoFlags |= SDL_HWSURFACE;
    else
        videoFlags |= SDL_SWSURFACE;

    // Do hardware video blits if possible
    if (videoInfo->blit_hw)
        videoFlags |= SDL_HWACCEL;

    // Set up OpenGL for double buffering in SDL
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Get our SDL surface to draw to
    surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, videoFlags);
    if (!surface)
    {
        cerr << "Video mode set failed: " << SDL_GetError() << endl;
        quit(1);
    }

    int audio_rate = 22050, audio_channels = 2, audio_buffers = 4096;
    Uint16 audio_format = AUDIO_S16SYS;

    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
    {
            cout << "Unable to initialize audio: " << Mix_GetError() << endl;
            exit(1);
    }

}


int initGL()
{
    //  Enable smooth shading (i.e. gouraud shading)
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Disable depth testing (because we're working in 2D!)
    glDisable(GL_DEPTH_TEST);

    // Enable blending (we need this to be able to use an alpha component)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set the accumulation buffer clearing colour to black at 0,0f alpha
    glClearAccum(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(5.0f);
    return 0;
}


// Function to reset the viewport after a window resize
int resizeWindow(int width, int height)
{
    GLfloat ratio;

    // Protect against a divide by zero error when resizing
    if (height == 0)
        height = 1;

    if (width == 0)
        width = 1;

    // Calculate our new (post-resize) window ratio
    if (width > height)
        ratio = (GLfloat)width / (GLfloat)height;
    else
        ratio = (GLfloat)height / (GLfloat)width;

    // Setup our viewport to be the entire size of the window
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    // Change to the projection matrix and reset the matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Change to orthographic (2D) projection and switch to the modelview matrix
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return 0;
}


void handleKeyPress(SDL_keysym *keysym)
{
    switch(keysym->sym)
    {
        case SDLK_ESCAPE:
            quit(0);
            break;
        case SDLK_F1:   // F1 key pressed? Then toggle fullscreen mode
            SDL_WM_ToggleFullScreen(surface);
            break;
        default:    // Do nothing by default!
            break;
    }
}


void PlaySound()
{
        int channel;
        Mix_Chunk *sound = NULL;
        sound = Mix_LoadWAV("Visphotak.wav");
        if(sound == NULL)
                printf("Unable to load WAV file: %s\n", Mix_GetError());

        channel = Mix_PlayChannel(2, sound, 0);
        if(channel == -1)
                printf("Unable to play WAV file: %s\n", Mix_GetError());

        // while(Mix_Playing(channel) != 0);
        Mix_Playing(channel);
        // Mix_FreeChunk(sound);
}

int ex[FIREWORKS] = {0};

int drawScene()
{
    // Set our clear mode to clear the screen -only-
    glClear(GL_COLOR_BUFFER_BIT);

    // Take the contents of the current accumulation buffer and copy it to the
    // colour buffer with each pixel multiplied by a factor i.e. we clear the screen,
    // draw the last frame again (which we saved in the accumulation buffer),
    // then draw our stuff at its new location on top of that
    glAccum(GL_RETURN, 0.95f);

    // Clear the accumulation buffer
    glClear(GL_ACCUM_BUFFER_BIT);

    // Set ModelView matrix mode and reset to the default identity matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Displacement trick for exact pixelization
    glTranslatef(0.375, 0.375, 0);


    // Draw fireworks
    for (int loop = 0; loop < FIREWORKS; loop++)
    {

        for (int particleLoop = 0; particleLoop < FIREWORK_PARTICLES; particleLoop++)
        {
            // Set the point size of the firework particles
            glPointSize(fw[loop].particleSize);

            glBegin(GL_POINTS);
                // Set colour to yellow on way up, then whatever colour firework should be when exploded
                if (!fw[loop].hasExploded)
                    glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                else
                    glColor4f(fw[loop].red, fw[loop].green, fw[loop].blue, fw[loop].alpha);

                // Draw the point
                glVertex2f(fw[loop].x[particleLoop], fw[loop].y[particleLoop]);
            glEnd();
        }

        // Move the firework appropriately depending on its explosion state
        if (!fw[loop].hasExploded)
        {
            fw[loop].move();
            ex[loop] = 0;
        }
        else
        {
            fw[loop].explode();
            // cout<<loop<<endl;
            if(ex[loop] == 0)
            {
                PlaySound();
                ex[loop] = 1;
            }
        }
    }

    // Swap active and visual pages to display our output to the screen
    SDL_GL_SwapBuffers();

    // Take the contents of the current draw buffer and copy it to the
    // accumulation buffer with each pixel modified by a factor. The closer
    // the factor is to 1.0f, the longer the trails... Don't exceed 1.0f - you get garbage.
    glAccum(GL_ACCUM, 0.9f);

    return 0;
}


// Function to handle all SDL events appropriately
void controlLoop(int& videoFlags, SDL_Event& event)
{
    // Static var to keep track of whether we should now exit or not
    static bool done = false;
    while (!done)
    {
        // Handle the events in the queue
        while (SDL_PollEvent(&event))
        {
            // Depending on what event has occured, handle it appropriately
            switch (event.type)
            {
                case SDL_VIDEORESIZE:
                    surface = SDL_SetVideoMode(event.resize.w, event.resize.h, SCREEN_BPP, videoFlags);
                    if (!surface)
                    {
                        cerr << "Could not get a surface after resize: " << SDL_GetError() << endl;
                        quit(1);
                    }
                    resizeWindow(event.resize.w, event.resize.h);
                    break;
                case SDL_KEYDOWN:
                    handleKeyPress(&event.key.keysym);
                    break;
                case SDL_QUIT:
                    done = true;
                    break;
                default:
                    break;
            }
        }
        drawScene();

        // Cheap-as-chips limit framerate to approximately 60fps
        SDL_Delay(16);
    }
}


int main(int argc, char **argv)
{
    // Flags to pass to SDL_SetVideoMode - made global for use in setupScreen and controlLoop functions
    int videoFlags;

    // SDL_Event type variable to keep track of events (used in controlLoop function)
    SDL_Event event;

    // Seed random number generator
    srand(time(NULL));

    setupScreen(videoFlags);

    // Set the window and tray caption
    SDL_WM_SetCaption("Fireworks", "Fireworks");

    initGL();
    resizeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Call our control loop - this the main loop that keeps on running until user quits program with Esc or by closing the display window
    controlLoop(videoFlags, event);

    // Clean ourselves up and exit
    Mix_CloseAudio();
    quit(0);
    return 0;
}
