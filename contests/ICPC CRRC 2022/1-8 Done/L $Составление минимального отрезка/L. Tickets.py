class Segment:
    weekDays = ["monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"]
    minutesPerDay = 1440
    minutesPerWeek = 100_80

    def __init__(self):
        dataIn = [i.split(":") for i in input().split()]
        self.seg = {"l": Segment.weekDays.index(*dataIn[0]) * Segment.minutesPerDay + int(dataIn[1][0]) * 60 + int(dataIn[1][1]),
                    "r": Segment.weekDays.index(*dataIn[2]) * Segment.minutesPerDay + int(dataIn[3][0]) * 60 + int(dataIn[3][1])}

        self.whole = self.seg["r"] > self.seg["l"]

        self.dist = self.seg["r"] - self.seg["l"] if self.whole else Segment.minutesPerWeek - (self.seg["l"] - self.seg["r"])

# main = [l,r], other = [a,b]
    @staticmethod
    def calcDistForward(main, other):
        # 1. b <= l
        if other.seg["r"] <= main.seg["l"]:
            return other.dist + main.seg["l"] - other.seg["r"]
        # 2. b > l
        else:
            return other.dist + Segment.minutesPerWeek - (other.seg["r"] - main.seg["l"])

    @staticmethod
    def calcDistBack(main, other):
        # 1. a >= r
        if other.seg["l"] >= main.seg["r"]:
            return other.dist + other.seg["l"] - main.seg["r"]
        # 2. a < r
        else:
            return other.dist + Segment.minutesPerWeek - (main.seg["r"] - other.seg["l"])


mainSeg = Segment()  # [a,b]
nTrainsForward, nTrainsBack = (int(i) - 1 for i in input().split())

minTimeForward = Segment.calcDistForward(mainSeg, Segment())
for i in range(nTrainsForward):
    curTimeForward = Segment.calcDistForward(mainSeg, Segment())
    if curTimeForward < minTimeForward:
        minTimeForward = curTimeForward


minTimeBack = Segment.calcDistBack(mainSeg, Segment())
for i in range(nTrainsBack):
    curTimeBack = Segment.calcDistBack(mainSeg, Segment())
    if curTimeBack < minTimeBack:
        minTimeBack = curTimeBack

print(minTimeForward + mainSeg.dist + minTimeBack)