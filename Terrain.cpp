#ifdef __APPLE__
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

#include <cstdlib>
#include <unordered_map>

const int LENGTH = 1000;
const int HEIGHT = 1000;


class PerlinNoiseGenerator {
private:
	int fractality;
	std::unordered_map<std::array<int, 2>, float*> intersections;

	float interpolate(float a0, float a1, float w) {
		return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
	}

	vector generateRandomVector() {
		vector result;
		float x = ((float)std::rand() * 2 / RAND_MAX) - 1;
		float y = ((float)std::rand() * 2 / RAND_MAX) - 1;

		float magnitude = sqrt(x * x + y * y);

		result.x = x / magnitude;
		result.y = y / magnitude;

		return result;
	}

	float dotProduct(std::array<int, 2> grid, float x, float z) {
		if (intersections.find(grid) != intersections.end()) {
			intersections[grid] = generateRandomVector();
		}
		vector gradient = intersections[grid];

		float dx = x - (float)grid.x;
		float dz = z - (float)grid.z;

		return (dx * gradient.x + dz * gradient.z);
	}

public:
	PerlinNoiseGenerator(int fractality) : fractality(fractality) {
	}

	float getNoiseValue(point location) {
		float relx = location.x / fractality;
		float rely = location.y / fractality;

		int x0 = (int)relx;
		int x1 = x0 + 1;

		int y0 = (int)rely;
		int y1 = y0 + 1;	


	}

	float getNoiseValue(int x, int z) {
		point location;
		location.x = x;
		location.z = z;

		return getNoiseValue(location);
	}
};
