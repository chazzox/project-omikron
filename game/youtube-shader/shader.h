char *shader_fragment[] = {
    "uniform float time;"
    "uniform vec2 resolution; "
    "vec3 flag (vec2 uv) {"
    "vec3 colG = min (mix (vec3(0.0), vec3(0.8, 0.7, 0.1), step (0.33, 1-uv.y)), mix (vec3 (0.0), vec3 (0.8, 0.7, 0.1), step (0.33, uv. y)));"
    "vec3 colW = mix (vec3(0.0), vec3 (0.8), step(0.67, 1-uv. y));"
    "vec3 colB = mix (vec3 (0.0), vec3 (0.3), step (0.67, uv.y));"
    "return colW+colG+colB;}"
    "void main(void) {"
    "vec2 position = vec2 (gl_FragCoord.x/resolution.x-0.1,gl_FragCoord.y/resolution.y-0.1)*1.25;"
    "vec3 col; float a = 1.0; vec3 colY; vec3 colX;"
    "float x = sin(position.x* 20.0+ time * 6.0) * sin(position.x* 5.0+ time * 3.0);"
    "position.x += sin(position.y+time*2.0) *.05;"
    "position.y += sin(position.x*2.0-time* 2.0) *0.1 +0.02 * x;"
    "if (abs (1-position.y)< 1.0) { if (abs (position.y)< 1.0) {colY = flag (position);}}"
    "if (abs (1-position.x) < 1.0) { if (abs (position.x) < 1.0) {colX = flag (position);}}"
    "col = colY*colX;"
    "vec2 uv = gl_FragCoord/resolution; "
    "if (col == vec3(0.0)) { col = vec3(0.2,0.4,0.8) + 0.15*cos (time+uv.yxy+vec 3 (0,2,4));}"
    "else {col = 0.4* (x * 0.5 + 0.5);}"
    "gl_FragColor = vec4 (col, a );}"};

void shader(char **src, int type, int program)
{
    int shader = glCreateShader(type);
    glShaderSource(shader, 1, src, 0);
    glCompileShader(shader);
    glAttachShader(program, shader);
}