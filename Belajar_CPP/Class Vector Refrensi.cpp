#include <iostream>
#include <vector>

class Object
{
	public:
		Object()
		{}
		~Object()
		{}
		void AddInt(int num)
		{
			m_VectorOfInts.push_back(num);
		}
		std::vector<int> GetCopyOfVector()
		{
			return m_VectorOfInts;
		}
		void DisplayVectorContents()
		{
			for( unsigned int i = 0; i < m_VectorOfInts.size(); i++ )
			{
				std::cout << "Element[" << i << "] = " << m_VectorOfInts[i] << std::endl;
			}
			std::cout << std::endl;
		}

	private:
		std::vector<int> m_VectorOfInts;
};

int main()
{
	// Create our class an add a few ints
	Object obj;
	obj.AddInt(32);
	obj.AddInt(56);
	obj.AddInt(21);

	// Display the vector contents so far
	obj.DisplayVectorContents();

	// Creates a copy of the classes container you can only really view whats in 
	// the classes vector container. What ever changes you make here wont effect the class.
	std::vector<int> container1 = obj.GetCopyOfVector();
	// These elements wont be added as it's a copy of the container
	container1.push_back(342);
	container1.push_back(64);
	container1.push_back(123);


	// Display the classes container to see show nothing was added.
	obj.DisplayVectorContents();

	return 0;
}