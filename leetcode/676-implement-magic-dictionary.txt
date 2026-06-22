def __init__(self):
    self.data = []

def buildDict(self, dictionary: List[str]) -> None:
    self.data = dictionary

def search(self, searchWord: str) -> bool:
    for i in self.data:
        if len(i) != len(searchWord):
            continue
        sanoq = 0
        for j in range(len(i)):
            if i[j] != searchWord[j]:
                sanoq +=1
        if sanoq == 1:
            return True
    return False