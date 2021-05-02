#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model grass;
    Model sky;
    Model crocus;
    Model sd;
    Model fox;
    Model bear;
    Model deer;
    Model house;
    Model dog;
    Model gift;
    Model help;
    Material material;
    GLuint grass_texture_id;
    GLuint sky_texture_id;
    GLuint crocus_texture_id;
    GLuint sd_texture_id;
    GLuint fox_texture_id;
    GLuint bear_texture_id;
    GLuint deer_texture_id;
    GLuint house_texture_id;
    GLuint dog_texture_id;
    GLuint gift_texture_id;
    GLuint help_texture_id;
    double w;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Update the scene by loading models.
 */
void update_scene(Scene* scene, double time);


/**
 * Set the lighting of the scene.
 */
void set_lighting(GLfloat brightness);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();





#endif /* SCENE_H */
