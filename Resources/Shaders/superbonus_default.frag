uniform sampler2D texture;
uniform float time;

void main()
{
	gl_FragColor = gl_Color * texture2D(texture, gl_TexCoord[0].xy);
}