1.
    a. Daisy Zahory Fernandez-Reyes
    b. 2397370
    c. CPSC-350-01
    d. Not So Super Mario Bros; PA2
2. 
    Project Overview (list of all source of files):

    fileReader.h
    fileReader.cpp
        a. reads input.txt and returns int values for  
                1. Levels
                2.  dimensions of Grid
                3. total lives
                4. percentage of coins
                5. percent of empty spaces (adds up to 100)
                5. percent of koopa spaces (adds up to 100)
                7.  percent of goomba spaces (adds up to 100)
                8. percent of musroom spaces  (adds up to 100)
        b. parameters
            constructors :
                fileReader()

            destructors:   
                ~fileReader();

            member functions:
                int readAndPrintFile(const string& fileName);

            member variables:
                int amountLevels;
                int gridSize;
                int totalLives;
                int percentCoins;
                int percentNothing;
                int percentKoopas;
                int percentGoombas;
                int percentMushrooms;

            getters: 
                int getLevels() const;
                int getDimension() const;
                int getLives() const;
                int getCoins() const;
                int getNothing() const;
                int getGoombas() const;
                int getKoopas() const;
                int getMushrooms() const;

        c. exceptions thrown:
            try-catch in readAndPrintFile: 
                converts eachline of a file to stoi(text), if 
                this fails the invalid_argument excpetion is thrown.


3. 
    Description of runtime errors (if any): 
    no! <3
4. 
    list of references used to complete the assignment:
    zybooks!
5. 
    instructions on running the assignment:
    
    a.  if you're going to test using own input file: 
            -  rename file to 'input.txt'
            or
            - if thats too much then copy + paste desired input.txt values into input.txt
    b. compiling and running directions:   
        in the terminal: 
            g++ main.cpp fileReader.cpp Grid.cpp -o dawg
            ./dawg
        




