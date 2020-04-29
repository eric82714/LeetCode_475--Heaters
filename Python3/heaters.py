class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses = sorted(houses)
        heaters = sorted(heaters)
        
        if len(heaters) == 1:
            return max(heaters[0] - houses[0], houses[-1] - heaters[0])
        elif len(houses) == 1:
            return min([abs(houses[0]-heaters[i]) for i in range(len(heaters))])
        else:
            radius = 0
            pos = 0
            heaters = [float('-inf')] + heaters + [float('inf')]
            
            for house in houses:
                while house >= heaters[pos]:
                    pos += 1
                tmp = min(house - heaters[pos - 1], heaters[pos] - house)
                radius = max(radius, tmp)
                
            return radius
