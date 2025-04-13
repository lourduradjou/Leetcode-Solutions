class Solution:
    def findMinPoints(self, x1 : int, x2 : int, y1 : int , y2 : int) -> int:
        return max(abs(x2-x1), abs(y2-y1))

    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        res = 0
        x1, y1 = points.pop()

        while points:
            x2, y2 = points.pop()
            res += self.findMinPoints(x1,x2,y1,y2) 
            x1, y1 = x2, y2

        return res