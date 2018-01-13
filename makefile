all:
	clear 
	g++ main.cpp deathStar.cpp -o deathStar -lglut -lGL -lGLU #-lstdc++ -lc -lm 	
	./deathStar
	

