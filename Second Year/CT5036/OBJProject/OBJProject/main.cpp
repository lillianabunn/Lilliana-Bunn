#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string lineType(const std::string& in)
{
	if (!in.empty())
	{
		size_t token_start = in.find_first_not_of(" \t");
		size_t token_end = in.find_first_of(" \t, token_start");
		if (token_start != std::string::npos && token_end != std::string::npos)
		{
			return in.substr(token_start);
		}
		else if (token_start != std::string::npos)
		{
			return in.substr(token_start);
		}
	}
	return "";
}

int main(int argv, char* argc[])
{
	std::string filename = "obj_models/basic_box.OBJ";
	std::cout << "Attempting to open file: " << filename << std::endl;
	//get an fstream to read in the file data
	std::fstream file;
	file.open(filename, std::ios_base::in | std::ios_base::binary);
	//test to see if the file has opened in correctly
	if (file.is_open())
	{
		std::cout << "Successfully Opened" << std::endl;
		//success file has been opened, verify contents of file -- ie check that file is not zero length
		file.ignore(std::numeric_limits<std::streamsize>::max());	//attempt to rad the highest number of bytes from the file
		std::streamsize fileSize = file.gcount();					//gCount will have reached EOF marker. letting us know number of bytes
		file.clear();												//clear EOF marker from being read
		file.seekg(0, std::ios_base::beg);							//seek back to the beginning of the file
		if (fileSize == 0)											//if our file has no data close the file and return early
		{
			std::cout << "File contains no data, closing file" << std::endl;
			file.close();
		}
		std::cout << "File size: " << fileSize / 1024 << " KB" << std::endl;

		std::string fileLine;
		std::vector<std::string> vertexData;
		std::vector<std::string> normalData;
		std::vector<std::string> faceData;
		//Set up reading in chunks of a file at a time
		while (!file.eof())
		{
			for (int i = 0; i < 32; ++i)
			{
				if (std::getline(file, fileLine))
				{
					if (fileLine.size() > 0)
					{
						std::string dataType = lineType(fileLine);
						if (dataType == "v")
						{
							vertexData.push_back(fileLine); //This is incomplete first substring to split off token
							//then split substring at each instance of " " to get vertex number components
							//store number string as float stf::stof works for this
						}
						if (dataType == "vt") {}
						if (dataType == "vn") {}
						if (dataType == "f") {}
					}
				}
			}
		}
		file.close();
	}
	return EXIT_SUCCESS;
}