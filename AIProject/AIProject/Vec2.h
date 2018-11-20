#pragma once
#include <iostream>
#include <time.h>
#include "Vec2.h"
namespace PlayerInfo
{
	class Vector2
	{
	public:

		Vector2(float a, float b)
		{
			x = a;
			y = b;
		}
		Vector2() {}
		void MoveTowards(Vector2 *position) // WIth a .1
		{
			Vector2 *newPos = new Vector2(*this);
			if (this != position)
			{
				if (newPos->x < position->x)
				{
					newPos->x += 0.1f;
				}
				else if (newPos->x > position->x)
					newPos->x -= 0.1f;
				if (newPos->y < position->y)
				{
					newPos->y += 0.1f;
				}
				else if (newPos->y > position->y)
					newPos->y -= 0.1f;
			}
			else if (newPos > position)
			{
				newPos->x -= .1f;
				newPos->y -= .1f;
			}
			if (std::abs(newPos->x - position->x) < 0.2f)
			{
				newPos->x = position->x;
			}
			if (std::abs(newPos->y - position->y) < 0.2f)
			{
				newPos->y = position->y;
			}
			// Check whether the position is already taken.. Collision
			*this = *newPos;
			//if (game->isCoordinateTaken(*newPos))
			//	{
			//find new position
			//	}
			//	std::cout << *this << std::endl;

		}
		Vector2& RandomVector()
		{
			std::srand(time(NULL));
			*this = Vector2(rand() % 50 + 5, rand() % 75 + 5);
			return *this;
		}
		Vector2& Add(const Vector2 &other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}
		Vector2& Multiply(const Vector2 &other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}
		Vector2& Divide(const Vector2 &other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}
		Vector2& Subtract(const Vector2 &other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		friend Vector2 operator+(Vector2 left, const Vector2 right)
		{
			return left.Add(right);
		}
		friend Vector2 operator-(Vector2 left, const Vector2 right)
		{
			return left.Subtract(right);
		}
		friend Vector2 operator*(Vector2 left, const Vector2 right)
		{
			return left.Multiply(right);
		}
		friend Vector2 operator/(Vector2 left, const Vector2 right)
		{
			return left.Divide(right);
		}
		Vector2& operator+=(const Vector2 other)
		{
			return Add(other);
		}
		Vector2& operator-=(const Vector2& other)
		{
			return Subtract(other);
		}
		Vector2& operator*=(const Vector2& other)
		{
			return Multiply(other);
		}
		Vector2& operator/=(const Vector2& other)
		{
			return Divide(other);
		}
		bool operator==(const Vector2& other)
		{
			return x == other.x && y == other.y;
		}
		bool operator!=(const Vector2& other)
		{
			return !(*this == other);
		}
		friend std::ostream& operator << (std::ostream& stream, const Vector2& vector)
		{
			stream << "vec2: ( " << vector.x << " , " << vector.y << " )";
			return stream;
		}

	public:
		float x; // These will be the goto functions that move the ai to different positions
		float y;
	};
}
//vec2 operator+(vec2 left, const vec2 right)
//{
//	return left.add(right);

//}

