david = [[1967, 'DavidBowie'], [1969, 'SpaceOddity'], [1970, 'TheManWhoSoldTheWorld'], [1971, 'HunkyDory'],
[1972, 'TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars'], [1973, 'AladdinSane'], [1973, 'PinUps'],
[1974, 'DiamondDogs'], [1975, 'YoungAmericans'], [1976, 'StationToStation'], [1977, 'Low'], [1977, 'Heroes'],
[1979, 'Lodger'], [1980, 'ScaryMonstersAndSuperCreeps'], [1983, 'LetsDance'], [1984, 'Tonight'],
[1987, 'NeverLetMeDown'], [1993, 'BlackTieWhiteNoise'], [1995, '1.Outside'], [1997, 'Earthling'],
[1999, 'Hours'], [2002, 'Heathen'], [2003, 'Reality'], [2013, 'TheNextDay'], [2016, 'BlackStar']]

def starman(n):
    s,e = map(int,input().split())
    for d in david:
        if s <= d[0] and d[0] <= e:
            yield d
                
n_q = int(input())
for n in range(0,n_q):
    ans = list(starman(n_q))
    print(len(ans))
    for a in ans:
        print(a[0], a[1])
            
