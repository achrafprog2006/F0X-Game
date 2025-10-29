#version 330 core

in vec2 TexCoord;        
out vec4 FragColor;

uniform sampler2D ambientTexture; 
uniform float time;

uniform bool uTexture;

void main() {

FragColor=vec4(0.3,0.4,0.7,1.0);
if(uTexture){
    FragColor = texture(ambientTexture, TexCoord);
}
 
}