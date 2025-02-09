#version 330

// Input vertex attributes
in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec3 vertexNormal;
in vec4 vertexColor;

// Input uniform values
uniform mat4 mvp;
uniform mat4 matModel;
uniform mat4 matNormal;
uniform mat4 matView;
uniform mat4 lightSpaceMatrix;

// Output vertex attributes (to fragment shader)
out vec3 fragPosition;
out vec2 fragTexCoord;
out vec3 fragNormal;

out vec4 fragPosLightSpace;
out vec3 toCameraVector;

void main()
{
    // Send vertex attributes to fragment shader
    fragPosition = vec3(matModel * vec4(vertexPosition, 1.0));
    fragTexCoord = vertexTexCoord;
    fragNormal = normalize(vec3(matNormal * vec4(vertexNormal, 1.0)));

    fragPosLightSpace = lightSpaceMatrix * matModel * vec4(vertexPosition, 1.0);
    toCameraVector = (inverse(matView) * vec4(0,0,0,1)).xyz - fragPosition.xyz;

    // Calculate final vertex position
    gl_Position = mvp * vec4(vertexPosition, 1.0);
}
