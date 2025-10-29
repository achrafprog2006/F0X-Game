#version 330 core

  layout(location=0)in vec3 pos;
  layout(location=1)in vec3 nor;
  layout(location=2)in vec2 tex;


  uniform float time;

  uniform mat4 transformationMat;
  uniform mat4 viewMat;
  uniform mat4 projectionMat;

  out  vec2 TexCoord;

void main(){
  
   TexCoord=tex;

   gl_Position = projectionMat*viewMat*transformationMat*vec4(pos,1.0);  
    
}