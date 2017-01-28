#A kidnapper wrote a ransom note but is worried it will be traced back to him. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use whole words available in the magazine, meaning he cannot use substrings or concatenation to create the words he needs.

#Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

#Input Format

#The first line contains two space-separated integers describing the respective values of  (the number of words in the magazine) and  (the number of words in the ransom note).
#The second line contains  space-separated strings denoting the words present in the magazine.
#The third line contains  space-separated strings denoting the words present in the ransom note.

#Constraints
#Each word consists of English alphabetic letters. The words in the note and magazine are case-sensitive.

#Output format
#Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.

#Sample Input
#6 4
#give me one grand today night
#give one grand today

#Sample Output
#Yes

def ransom_note(magazine, ransom):
  wordinMagazine = dict()
    wordinRansome = dict()
    
    for word in magazine:
      if word not in wordinMagazine:
        wordinMagazine[word] = 0
        wordinMagazine[word] = wordinMagazine[word] + 1
    for word in ransom:
      if word not in wordinMagazine:
        return False
        if wordinMagazine[word] < 1:
          return False
        wordinMagazine[word] = wordinMagazine[word] - 1
    return True

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
  print("Yes")
else:
  print("No")
