#include "BaseDeserializer.h"
#include "Resources.h"

#define sameKey(k, t) strcmp(k, t) == 0

void parseGraphics(json_t* root, GraphicsComponent* gc)
{
    const char *key;
    json_t *value;
    json_object_foreach(root, key, value) 
    {
        if(sameKey(key, "texture"))
        {
            const char* resName = json_string_value( json_object_get(root, key) );
            gc->texture = Resources::Instance().LoadTextureRes(resName);
        }
        else if(sameKey(key, "textureArea"))
        {
            int x, y, width, height;
            json_unpack(json_object_get(root, key), "[i,i,i,i]", &x, &y, &width, &height);
            gc->textureArea.position.x = (float)x;
            gc->textureArea.position.y = (float)y;
            gc->textureArea.dimensions.x = (float)width;
            gc->textureArea.dimensions.y = (float)height;
        }
    }
}

void parsePosition(json_t* root, PositionalComponent* pc)
{
    const char *key;
    json_t *value;
    json_object_foreach(root, key, value) 
    {
        if(sameKey(key, "position"))
        {
            int x, y;
            json_unpack(json_object_get(root, key), "[i,i]", &x, &y);
            pc->position = Vector2((float)x,(float)y);
        }
        else if(sameKey(key, "rotation"))
        {
            pc->rotation = (float) json_real_value( json_object_get(root, key));
        }
        else if(sameKey(key, "scale"))
        {
            pc->scale = (float) json_real_value( json_object_get(root, key));
        }
        else if(sameKey(key, "rotationCentered"))
        {
            json_unpack(json_object_get(root, key), "b", &pc->rotationCentered);
        }
    }
}