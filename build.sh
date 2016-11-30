echo "Compiling..."
g++ main.cpp includes/Physics.cpp includes/Draw.cpp -o main -lsfml-system -lsfml-window -lsfml-graphics
echo "Done!"