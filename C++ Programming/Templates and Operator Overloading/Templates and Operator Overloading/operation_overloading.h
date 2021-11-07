class Overloading
{
public:
	Overloading(int x, int y)
	{
		this->x = x; 
		this->y = y;
	}

	void print() const
	{
		std::cout << x << ", " << y << "\n";
	}

	friend Overloading &operator+(Overloading o1, Overloading o2);
private:
	int x, y;
};

Overloading &operator+(Overloading o1, Overloading o2)
{
	Overloading* out = new Overloading(o1.x + o2.x, o1.y + o2.y);
	return *out;
}