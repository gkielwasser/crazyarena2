#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

class Obstacle {
		protected:
			int damages;

		public:
			Obstacle();
			Obstacle(const Obstacle &);
			Obstacle();
			~Obstacle();
};

#endif // OBSTACLE_H_INCLUDED
