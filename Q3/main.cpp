# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include<sstream>

using namespace std;

enum OrderType
{
	Ascending,
	Descending
};

enum SortType
{
	Bubble,
	Selection
};

struct TextFileData
{
	vector<int> array;
	OrderType orderType;
	SortType  sortType;
};

bool bubbleSort(vector<int>& array, OrderType orderType)
{
	const int arraySize = array.size();
	
	switch(orderType)
	{
	case Ascending:
		for (int i = 1; i < arraySize; ++i)
		{
			for (int k = 0; k < arraySize - i; ++k)
			{
				if (array[k] > array[k + 1])
				{
					int tmp  = array[k];
					array[k] = array[k+1];
					array[k+1] = tmp;
				}
			}
		}
		break;

	case Descending:
		for (int i = 1; i < arraySize; ++i)
		{
			for (int k = 0; k < arraySize - i; ++k)
			{
				if (array[k] < array[k + 1])
				{
					int tmp  = array[k];
					array[k] = array[k+1];
					array[k+1] = tmp;
				}
			}
		}
	}

    return true;
}

bool selectionSort(vector<int>& array, OrderType orderType)
{
	const int arraySize = array.size();
	
	
	switch(orderType)
	{
	case Ascending: 
		for (int i = 0; i < arraySize; ++i)
		{
			int max = array[0];
			int max_index = 0;
			for (int k = 1; k < arraySize - i; ++k)
			{
				if (max < array[k])
				{
					max = array[k];
					max_index = k;
				}
			}
			int tmp = array[arraySize-i-1];
			array[arraySize-i-1] = array[max_index];
			array[max_index] = tmp;
		}
		break;
		
	case Descending:
		for (int i = 0; i < arraySize; ++i)
		{
			int min = array[0];
			int min_index = 0;
			for (int k = 1; k < arraySize - i; ++k)
			{
				if (min > array[k])
				{
					min = array[k];
					min_index = k;
				}
			}
			int tmp = array[arraySize-i-1];
			array[arraySize-i-1] = array[min_index];
			array[min_index] = tmp;
		}
	}
	
	return true;
}

class TextFileReader
{
public:
	TextFileReader() = default;
	TextFileReader(string fileName)
	{
		m_fileName = fileName;
	}
	
	bool read(TextFileData& data)
	{
		ifstream ifs(m_fileName);
	
		if (ifs.fail())
		{
			cout << "File do not exist.";
			return false;
		}
		
		vector<string> strBuff;
		string str;
		while (getline(ifs, str))
		{
		  strBuff.push_back(str); 
		}
		
		vector<int> v;
		stringstream ss{strBuff[0]};
		string buf;
		while (std::getline(ss, buf, ':')) {
			v.push_back(stoi(buf));
		}
		data.orderType = (OrderType)v[0];
		data.sortType  = (SortType) v[1];
		
		ss = stringstream{strBuff[2]};
		while (std::getline(ss, buf, ' ')) {
			data.array.push_back(stoi(buf));
		}
		
		return true;
	}
	
	
private:
	string m_fileName;
};

class TextFileWriter
{
public:
	TextFileWriter() = default;
	TextFileWriter(string fileName)
	{
		m_fileName = fileName;
	}
	
	bool write(const TextFileData& data)
	{
		ofstream ofs(m_fileName);
		ofs << data.orderType << ':';
		
		for (int i = 0; i < data.array.size(); ++i)
		{
			ofs << data.array[i] << ' ';
		}
		
		return true;
	}
	
	
private:
	string m_fileName;
};

int main() 
{
    TextFileData data;
	TextFileReader reader("question.txt");

	reader.read(data);
	
	
	switch (data.sortType)
	{
	case Bubble:
		cout << "bubble sort" << endl;
		bubbleSort(data.array, data.orderType);
		break;
	case Selection:
		cout << "selection sort" << endl;
		selectionSort(data.array, data.orderType);
	}
	
	
    for (int i = 0; i < data.array.size(); ++i)
    {
        cout << data.array[i] << " ";
    }

	TextFileWriter writer("answer.txt");
	writer.write(data);
	
    return 0;
}