class Robot:

    def __init__(self, width: int, height: int):
        self.isMoved = False
        self.width = width
        self.height = height
        self.simulation = []
        self.ind = 0

        for i in range(width): #left to right
            self.simulation.append([i, 0, 0])
        for i in range(1,height): #right to up
            self.simulation.append([width-1, i, 1])
        for i in range(width-2,-1,-1): #right to left
            self.simulation.append([i, height-1, 2])
        for i in range(height-2, 0,-1): #up to down
            self.simulation.append([0, i, 3])


    def step(self, num: int) -> None:
        self.isMoved = True
        self.ind = (self.ind + num) % len(self.simulation)


    def getPos(self) -> List[int]:
        x, y, _ = self.simulation[self.ind]
        return [x,y]
        

    def getDir(self) -> str:
        if self.getPos() == [0,0] and self.isMoved == True:
            return "South"
        _, _, d = self.simulation[self.ind]
        dirName = ""
        if d == 0:
            dirName = "East"
        elif d == 1:
            dirName = "North"
        elif d == 2:
            dirName = "West"
        else:
            dirName = "South"
        
        return dirName


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()