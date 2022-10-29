#include <raylib-cpp.hpp>
#include <fstream>
#include <vector>

struct Vertex {
    double x, y, z;
    Vertex(double X, double Y, double Z) {
        x = X;
        y = Y;
        z = Z;
    }
};

struct Triangle {
    Vertex v1, v2, v3;
    Triangle(Vertex V1, Vertex V2, Vertex V3) {
        v1 = V1;
        v2 = V2;
        v3 = V3;
    }
};

std::vector< Triangle > parseSTLfile(std::string filepath) {

    std::vector< Triangle > parsedTriangles;
    std::vector< Vertex > vertexBuffer;

    // noob parsing strategy but works for now

    std::ifstream fin(filepath);

    std::string in;
    int x, y, z;

    while(fin >> in) {
        if(in == "vertex") {
            fin >> x >> y >> z;
            vertexBuffer.push_back( Vertex(x, y, z) );
        }

        if(vertexBuffer.size() == 3) {
            parsedTriangles.push_back( Triangle(
                vertexBuffer[0],
                vertexBuffer[1],
                vertexBuffer[2]
            ));
        }
    }

    return parsedTriangles;

}

int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    return 0;
}