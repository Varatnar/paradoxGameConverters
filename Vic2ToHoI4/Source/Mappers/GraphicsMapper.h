/*Copyright (c) 2017 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#ifndef GRAPHICS_MAPPER_H_
#define GRAPHICS_MAPPER_H_



#include <map>
#include <random>
#include <string>
#include <vector>
using namespace std;



class Object;



typedef struct
{
	map<string, vector<string>> element;
} cultureGroupToPortraitsMap;

typedef struct 
{
	map<string, cultureGroupToPortraitsMap> element;
} ideologyToPortraitsMap;



class graphicsMapper
{
	public:
		static string getLeaderPortrait(string cultureGroup, string ideology)
		{
			return getInstance()->GetLeaderPortrait(cultureGroup, ideology);
		}

		static string getIdeologyMinisterPortrait(string cultureGroup, string ideology)
		{
			return getInstance()->GetIdeologyMinisterPortrait(cultureGroup, ideology);
		}

	private:
		static graphicsMapper* instance;
		static graphicsMapper* getInstance()
		{
			if (instance == nullptr)
			{
				instance = new graphicsMapper;
			}
			return instance;
		}
		graphicsMapper();
		void loadLeaderPortraitMappings(const string& cultureGroup, Object* portraitMappings);
		void loadIdeologyMinisterPortraitMappings(const string& cultureGroup, Object* portraitMappings);

		string GetLeaderPortrait(string cultureGroup, string ideology);
		vector<string> GetLeaderPortraits(string cultureGroup, string ideology);
		string GetIdeologyMinisterPortrait(string cultureGroup, string ideology);
		vector<string> GetIdeologyMinisterPortraits(string cultureGroup, string ideology);

		ideologyToPortraitsMap leaderPortraitMappings;
		ideologyToPortraitsMap ideologyMinisterMappings;

		std::mt19937 rng;
};




#endif //GRAPHICS_MAPPER_H_