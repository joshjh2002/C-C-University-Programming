
template <typename T>
class templateClass
{
public:
	templateClass(T val1)
	{
		value = val1;
	}

	void doSomething()
	{
		std::cout << value << "\n";
	}
private:
	T value;
};