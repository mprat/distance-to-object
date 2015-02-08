CFLAGS = `pkg-config --cflags opencv` -stdlib=libstdc++
LIBS = `pkg-config --libs opencv`
LDFLAGS = -stdlib=libstdc++ -lstdc++
CXXFLAGS = -stdlib=libstdc++

all:
	g++ $(CXXFLAGS) $(CFLAGS) $(LIBS) main.cpp -o main.o