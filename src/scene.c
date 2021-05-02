#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

#include <math.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->grass), "grass.obj");
    scene->grass_texture_id = load_texture("grass.jpg");

    load_model(&(scene->sky), "grass.obj");
    scene->sky_texture_id = load_texture("sky.jpg");

    load_model(&(scene->crocus), "crocus.obj");
    scene->crocus_texture_id = load_texture("crocus.jpg");

    load_model(&(scene->sd), "sd.obj");
    scene->sd_texture_id = load_texture("sd2.jpg");

    load_model(&(scene->fox), "fox.obj");
    scene->fox_texture_id = load_texture("fox.jpg");

    load_model(&(scene->bear), "bear.obj");
    scene->bear_texture_id = load_texture("bear.jpg");

    load_model(&(scene->deer), "deer.obj");
    scene->deer_texture_id = load_texture("deer.jpg");

    load_model(&(scene->house), "house.obj");
    scene->house_texture_id = load_texture("house.jpg");

    load_model(&(scene->dog), "dog.obj");
    scene->dog_texture_id = load_texture("dog.jpg");

    load_model(&(scene->gift), "gift.obj");
    scene->gift_texture_id = load_texture("gift.jpg");

    load_model(&(scene->help), "help.obj");
    scene->help_texture_id = load_texture("help.jpg");

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;

}

void update_scene(Scene* scene,double time){
    scene->w += time;
}

void set_lighting(GLfloat brightness)
{
	set_lighting (0.75f);
	float ambient_light[] = { brightness, brightness, brightness, brightness };
    float diffuse_light[] = { brightness, brightness, brightness, brightness };
    float specular_light[] = { brightness, brightness, brightness, brightness };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    //set_lighting(0.75f);
    draw_origin();

    int time = glutGet(GLUT_ELAPSED_TIME);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->grass_texture_id);
    glTranslatef(0,2,0);
    glScalef(0.4,0.4,0.01);
    draw_model(&(scene->grass));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->sky_texture_id);
    glTranslatef(0,0,0);
    //glScalef(0.02,0.02,0.02);
    draw_model(&(scene->sky));
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1,0.5,0);
    glScalef(0.05,0.05,0.05);
    glBindTexture(GL_TEXTURE_2D, scene->crocus_texture_id);
    draw_model(&(scene->crocus));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,1,0);
    glScalef(0.09,0.09,0.09);
    glBindTexture(GL_TEXTURE_2D, scene->sd_texture_id);
    draw_model(&(scene->sd));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7,0,0.1);
    glScalef(0.1,0.1,0.1);
    glBindTexture(GL_TEXTURE_2D, scene->fox_texture_id);
    draw_model(&(scene->fox));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(11,7,2);
    glScalef(0.3,0.3,0.3);
    glBindTexture(GL_TEXTURE_2D, scene->bear_texture_id);
    draw_model(&(scene->bear));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,-5,1);
    glScalef(0.05,0.05,0.05);
    glRotatef(time/25, 0.0f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, scene->deer_texture_id);
    draw_model(&(scene->deer));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,0,1.8);
    glScalef(1.7,1.7,1.7);
    glBindTexture(GL_TEXTURE_2D, scene->house_texture_id);
    draw_model(&(scene->house));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16,0,0.6);
    glScalef(0.09,0.09,0.09);
    glRotatef(time/45, 0.0f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, scene->dog_texture_id);
    draw_model(&(scene->dog));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(21,1,0.6);
    glScalef(0.09,0.09,0.09);
    glBindTexture(GL_TEXTURE_2D, scene->gift_texture_id);
    draw_model(&(scene->gift));
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.0,0.0,0.0);
    glBindTexture(GL_TEXTURE_2D, scene->help_texture_id);
    draw_model(&(scene->gift));
    glPopMatrix();

}

void draw_origin()
{
    glBegin(GL_LINES);
/*
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
*/

    glEnd();
}
