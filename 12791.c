#include <stdio.h>

char Album_name[25][51] = {
	"DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory",
	"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars", "AladdinSane",
	"PinUps", "DiamondDogs", "YoungAmericans", "StationToStation",
	"Low", "Heroes", "Lodger", "ScaryMonstersAndSuperCreeps",
	"LetsDance", "Tonight", "NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside",
	"Earthling", "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar"
};

typedef struct Album {
	int year;
	int name;
}Album;

Album David[25] = {
	{1967, 0}, {1969, 1}, {1970, 2}, {1971, 3}, {1972, 4},
	{1973, 5}, {1973, 6}, {1974, 7}, {1975, 8}, {1976, 9},
	{1977, 10},{1977, 11}, {1979, 12}, {1980, 13}, {1983, 14}, 
	{1984, 15}, {1987, 16}, {1993, 17}, {1995, 18}, {1997, 19},
	{1999, 20}, {2002, 21}, {2003, 22}, {2013, 23}, {2016, 24}
};

int main() {
	int N;
	int S, E;
	int S_i, E_i;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &S, &E);

		int j = 0;
		while (David[j].year < S && j < 25)
			j++;
		S_i = j;

		while (David[j].year < E + 1 && j < 25)
			j++;
		E_i = j;

		printf("%d\n", E_i - S_i);
		if ((E_i - S_i) != 0) {
			for (j = S_i; j < E_i; j++)
				printf("%d %s\n", David[j].year, Album_name[David[j].name]);
		}
	}
	return 0;
}