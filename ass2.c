#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*  Initialize variables needed for animation  */

float spinX = 0.0;
float spinY = 0.0;
float zoomIn = 0.0;
float zoomOut = 0.0;


/*  Initialize material property and light source.  */
void myinit(void)
{
    // Light Properties
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {100.0, 100.0, 100.0, 0.0};
    
    //material properties
    GLfloat mat_specular[] = {0.5, 0.5, 0.5, 1.0};     
    GLfloat mat_shininess[]= {30.0};      

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Material Properties
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);  
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 

    // Enable Various Components
    glEnable(GL_COLOR_MATERIAL);  
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    
    // Transparency feature
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
	//Enable color material
    glColorMaterial(GL_FRONT,GL_DIFFUSE);
}
		
void animation()
{
	spinY += 3.0;
}

void stopAnimation()
{
	spinY = 0.0;
}

//key functions
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'x':
			spinX += 10.0;
			break;
	
		case 'X':
			spinY += 10.0;
			break;
		
		case 'Y':
			spinY += 10.0;
			break;
		
		case 'y':
			spinY += 10.0;
			break;
			
		case 'Z':
			zoomIn += 5.0;
			break;
			
		case 'z':
			zoomOut -= 5.0;
			break;
		
		case 'F':
			spinX += 50.0;
			break;
		
		case 'f':
			spinX += 50.0;
			break;
			
		case 'S':
			spinX += 0.1;
			break;
		
		case 's':
			spinX += 0.1;
			break;
		
		case 'T':
			stopAnimation();
			break;
			
		case 't':
			stopAnimation();
			break;
			
		case 27:
			exit(0);
			break;		
	}
}

//Simulator Toy
void toy()
{
	glPushMatrix();  // Green Torus
        glTranslatef(0.0, -1.5, -1.5);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3f(0.0, 0.5, 0.0);
        glutSolidTorus(0.275, 0.85, 15, 20);
      glPopMatrix();
      
      glPushMatrix();  // Blue Torus
        glTranslatef(0.0, -1.0, -1.5);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glutSolidTorus(0.275, 0.75, 12, 17);
      glPopMatrix();
      
      glPushMatrix();  // Red Torus
        glTranslatef(0.0, -0.55, -1.5);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glutSolidTorus(0.275, 0.65, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // Pink Torus
        glTranslatef(0.0, -0.1, -1.5);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 0.0, 1.0);
        glutSolidTorus(0.275, 0.55, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // yellow Torus
        glTranslatef(0.0, 0.35, -1.5);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        glutSolidTorus(0.275, 0.45, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // orange Torus
        glTranslatef(0.0, 0.75, -1.5);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 0.5, 0.0);
        glutSolidTorus(0.275, 0.35, 9, 14);
      glPopMatrix();

      glPushMatrix();  // Tall Yellow Box
        glTranslatef( 0.0, -3, -1.5);
        glRotatef(45.0, 0.0, 1.0, 0.0); 
        glScalef(1.0, 6.0, 1.0);    
        glColor3f(1.0, 1.0, 0.0);
        glutSolidCube(0.5);
      glPopMatrix();
      
       glPushMatrix();  // Tall Yellow Box
        glTranslatef( 0.0, 0.0, -1.5);
        glRotatef(45.0, 0.0, 1.0, 0.0); 
        glScalef(1.0, 6.0, 1.0);    
        glColor3f(1.0, 1.0, 0.0);
        glutSolidCube(0.5);
      glPopMatrix();

      glPushMatrix();  // Flat Blue Box
        glTranslatef( 0.0, -2.0, -1.5);
        glRotatef(45.0, 0.0, 1.0, 0.0); 
        glScalef(1.0, 0.2, 1.0);    
        glColor3f(0.4, 0.5, 1.0);
        glutSolidCube(2.0);
      glPopMatrix();

      glPushMatrix();  // Red Ball
        glTranslatef(0.0, 2.3, -1.5);
        glColor4f(1.0, 0.0, 0.0, 0.3);
        glutSolidSphere(0.85, 20, 10);
      glPopMatrix();
}

/* Draw various things */
void display()
{
    glLoadIdentity();
    gluPerspective( 40.0, 1.0 , 0.1,  120.0);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();

	//animation
	spinX += 0.0;
    spinY += 0.0;
	   
   	glPopMatrix();

    glPushMatrix();

      glRotatef(20.0, 1.0, 0.0, 0.0);
      glRotatef(spinY, 0.0, 1.0, 0.0);
      glRotatef(spinX, 1.0, 0.0, 0.0);
      glTranslatef(0.0,0.0,zoomIn);
      glTranslatef(0.0,0.0,zoomOut);
      
      //PYRAMIDS
      
      glPushMatrix(); //pyramids
      	glTranslatef(2.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(-4.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(-2.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(-6.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(4.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(0.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(-8.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      glPushMatrix(); //pyramids
      	glTranslatef(6.0,0.0,-8.0);
      	glRotatef(-30.0,0.0,0.0,1.0);
      	glScalef(5.0,5.0,5.0);
      	glColor3f(0.1,0.0,0.0);
      	glutSolidTetrahedron();
      glPopMatrix();
      
      //SNOWMAN
      
      glPushMatrix(); //biggest sphere
      	glTranslatef(3.0,-3.0,1.5);
      	glColor3f(1.0,1.0,1.0);
      	glutSolidSphere(1.0,20,30);
      glPopMatrix();
      
      glPushMatrix(); //medium sphere
      	glTranslatef(2.9,-1.5,1.5);
      	glColor3f(1.0,1.0,1.0);
      	glutSolidSphere(0.75,20,30);
      glPopMatrix();
      
      glPushMatrix(); //smallest sphere sphere
      	glTranslatef(2.85,-0.5,1.5);
      	glColor3f(1.0,1.0,1.0);
      	glutSolidSphere(0.45,20,30);
      glPopMatrix();
      
      glPushMatrix();  // one eye
        glTranslatef(2.8, -0.3, 1.9);
        glRotatef(90.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glutSolidTorus(0.025, 0.05, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // second eye
        glTranslatef(3.0, -0.3, 1.88);
        glRotatef(90.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glutSolidTorus(0.025, 0.05, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // nose
        glTranslatef(2.9, -0.4, 1.9);
        glRotatef(90.0, 0.0, 0.0, 0.0);
        glColor3f(1.0, 0.5, 0.0);
        glutSolidCone(0.05, 0.5, 9, 14);
      glPopMatrix();
      
      //PENGUIN 
      
      glPushMatrix(); //body
      	glTranslatef(-3.5,-3.0,1.5);
      	glColor3f(0.0,0.0,0.0);
      	glutSolidSphere(1.0,20,30);
      	glScalef(0.0,0.0,0.25);
      glPopMatrix();
      
      glPushMatrix(); //face
      	glTranslatef(-3.5,-2.15,1.5);
      	glColor3f(0.0,0.0,0.0);
      	glutSolidSphere(0.75,20,30);
      glPopMatrix();
      
      glPushMatrix(); //body
      	glTranslatef(-3.5,-3.0,2.05);
      	glColor3f(1.0,1.0,1.0);
      	glutSolidSphere(0.65,20,30);
      glPopMatrix();
      
      glPushMatrix(); //left eye
      	glTranslatef(-3.55,-1.75,1.95);
      	glColor3f(1.0,1.0,1.0);
      	glutSolidSphere(0.2,20,30);
      glPopMatrix();
      
      glPushMatrix(); //right eye
      	glTranslatef(-3.25,-1.75,1.9);
      	glColor3f(1.0,1.0,1.0);
      	glutSolidSphere(0.2,20,30);
      glPopMatrix();
      
      glPushMatrix();  // left pupil
        glTranslatef(-3.55, -1.65, 2.14);
        glRotatef(90.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glutSolidTorus(0.025, 0.05, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // right pupil
        glTranslatef(-3.2, -1.65, 2.1);
        glRotatef(90.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glutSolidTorus(0.025, 0.05, 9, 14);
	  glPopMatrix();
	  
	  glPushMatrix();  // nose
        glTranslatef(-3.375, -1.85, 2.12);
        glRotatef(90.0, 0.0, 0.0, 0.0);
        glColor3f(1.0, 0.5, 0.0);
        glutSolidCone(0.1, 0.5, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // left hand
      	glTranslatef(-4.2,-2.8,2.0);
        glRotatef(-45.0, 0.0, 1.0, 0.0);
        glColor3f(1.0, 0.5, 0.0);
        glutSolidCone(0.15, 0.85, 9, 14);
      glPopMatrix();
      
      glPushMatrix();  // right hand
      	glTranslatef(-2.7,-2.8,1.9);
        glRotatef(45.0, 0.0, 1.0, 0.0);
        glColor3f(1.0, 0.5, 0.0);
        glutSolidCone(0.15, 0.85, 9, 14);
      glPopMatrix();
      
   glPopMatrix();
    
    toy();    
	
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void myReshape(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(40.0, (GLfloat) h / (GLfloat) w , 0.1,  60.0);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    printf("KEY COMMANDS\n");
	printf("------------------------------------\n");
	printf("Zoom in : Z\n");
    printf("Zoom Out : z\n");
    printf("Rotation about X-axis : X or x\n");
    printf("Animation : A or a\n");
    printf("Animation faster : F or f\n");
    printf("Animation slower: S or s\n");
    printf("Pause animation : T or t\n");
    printf("Continue Animation : C or c\n");
    printf("Flat shaded polygonization : p\n");
    printf("Smooth shaded polygonization : P\n");
    printf("------------------------------------\n");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Random Display");
   
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);
    myinit();
    glutMainLoop();
	
    return 0;            
}
