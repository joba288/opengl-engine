#pragma once

#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>


#include <glm/glm.hpp>
#include "Mesh.h"

bool loadOBJ(const char* path, std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);

bool loadOBJ(const char* path, std::vector<Vertex> &vertices, std::vector<unsigned int> &indices){

    std::vector<unsigned int> posIndices, texCoordIndices, normalIndices;
    std::vector<glm::vec3> temp_positions;
    std::vector<glm::vec2> temp_texCoords;
    std::vector<glm::vec3> temp_normals;


    FILE * file = fopen(path, "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
        return false;
    }

    while( 1 ){

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader

        if (strcmp(lineHeader, "v") == 0 ){
            glm::vec3 position;
            fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z);
            temp_positions.push_back(position);

        }else if (strcmp( lineHeader, "vt") == 0 ){
            glm::vec2 texCoord;
            fscanf(file, "%f %f\n", &texCoord.x, &texCoord.y);
            temp_texCoords.push_back(texCoord);

        }else if (strcmp( lineHeader, "vn") == 0 ){
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        }else if (strcmp( lineHeader, "f" ) == 0 ){
            std::string vertex1, vertex2, vertex3;
            unsigned int posIndex[3], texCoordIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &posIndex[0], &texCoordIndex[0], &normalIndex[0], &posIndex[1], &texCoordIndex[1], &normalIndex[1], &posIndex[2], &texCoordIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("File can't be read\n");
                return false;
            }
            posIndices.push_back(posIndex[0]);
            posIndices.push_back(posIndex[1]);
            posIndices.push_back(posIndex[2]);
            texCoordIndices.push_back(texCoordIndex[0]);
            texCoordIndices.push_back(texCoordIndex[1]);
            texCoordIndices.push_back(texCoordIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }

    	// For each vertex of each triangle
	for( unsigned int i=0; i<posIndices.size(); i++ ){

		// Get the indices of its attributes
		unsigned int posIndex = posIndices[i];
		unsigned int texCoordIndex = texCoordIndices[i];
		unsigned int normalIndex = normalIndices[i];
		
		// Put the attributes in buffers
        Vertex v;

        
        v.positions = temp_positions[posIndex-1];
        v.texCoords = temp_texCoords[texCoordIndex-1];
        v.normals = temp_normals[normalIndex-1];


        vertices.push_back(v);
        indices.push_back(i);
	
	}
	fclose(file);

    

	return true;
}