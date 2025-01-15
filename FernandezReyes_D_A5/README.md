## 1.Author Info
    a. Daisy Zahory Fernandez-Reyes
    b. 2397370
    c. CPSC-350-01
    d. Programming Assignment 4; Scare Games 
## 2. Project Overview (list of all source of files):

- `main.cpp`
- `Monster.cpp`
- `Monster.h`
- `monsters.txt`
- `README.md`
- `runScareGames.cpp`
- `runScareGames.h`
- `ScareGames`
- `TournamentNode.h`
- `TournamentTree.h`

### file generated post compilation: 
 - `winners_Bracket.dot`
 - `losers_Bracket.dot`

## 3. runntime errors: 
    not that I'm aware of
    output results in "zsh: segmentation fault  ./ScareGames monsters.txt double" after completing requirements mystery segmentation fault is a resulf ot the use of 'raw pointers' according to 
    'https://www.cprogramming.com/debugging/segfaults.html#:~:text=There%20are%20four%20common%20mistakes,the%20end%20of%20an%20array.'
   
## 4. references: 

**general references references**
1. https://cplusplus.com/reference/vector/vector/
2. https://www.w3schools.com/cpp/cpp_vectors.asp
3. in class materials
- taken from in-class for node creation references and implementations such as node implementations
    - maxtree.h maxtree.cpp ; referenced from Dr.Eel's notion
    - Asked my peers to look at it @irene ichawan , and @jackson goldberg'22
    - Zybooks


### 5. instructions on running the assignment:
`g++ main.cpp RunScareGames.cpp Monster.cpp DOTFileGeneratorMethods.cpp -o ScareGames `

**for double elimiation:**  
- `./ScareGames monsters.txt double`

**for single elimination:**
- `./ScareGames monsters.txt single`
        




