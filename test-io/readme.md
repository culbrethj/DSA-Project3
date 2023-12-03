## Running your code with public io based tests  
 
To test your output locally, open a terminal preferably bash based e.g. **git bash**. Make sure you are in the Project1 directory. Then do the following to see your ouput for each test:  

#### Public Test 1:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/1.txt`
        
#### Public Test N (where N in the test case number):

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/N.txt`

<hr>

## Comparing your output with expected output

Alternatively, you can test your output with the expected output for the sample tests using the diff command. The diff command will not generate any output if your output matched the expected output. To run io based tests (At the Project1 directory): 

#### Public Test 1:

Run these three commands:

> g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp    

> build/test_io < test-io/input-files/1.txt > test-io/output-files/1.txt  

> diff -w test-io/expected-output-files/1.txt test-io/output-files/1.txt


##### Or Run this: 

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/1.txt > test-io/output-files/1.txt && diff -w test-io/expected-output-files/1.txt test-io/output-files/1.txt`


#### Public Test 2:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/2.txt > test-io/output-files/2.txt && diff -w test-io/expected-output-files/2.txt test-io/output-files/2.txt`

#### Public Test 3:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/3.txt > test-io/output-files/3.txt && diff -w test-io/expected-output-files/3.txt test-io/output-files/3.txt`

#### Public Test 4:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/4.txt > test-io/output-files/4.txt && diff -w test-io/expected-output-files/4.txt test-io/output-files/4.txt`

#### Public Test 5:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/5.txt > test-io/output-files/5.txt && diff -w test-io/expected-output-files/5.txt test-io/output-files/5.txt`

#### Public Test 6:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/6.txt > test-io/output-files/6.txt && diff -w test-io/expected-output-files/6.txt test-io/output-files/6.txt`

#### Public Test 7:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/7.txt > test-io/output-files/7.txt && diff -w test-io/expected-output-files/7.txt test-io/output-files/7.txt`

#### Public Test 8:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/8.txt > test-io/output-files/8.txt && diff -w test-io/expected-output-files/8.txt test-io/output-files/8.txt`

#### Public Test 9:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/9.txt > test-io/output-files/9.txt && diff -w test-io/expected-output-files/9.txt test-io/output-files/9.txt`

#### Public Test 10:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/10.txt > test-io/output-files/10.txt && diff -w test-io/expected-output-files/10.txt test-io/output-files/10.txt`

#### Public Test 11:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/11.txt > test-io/output-files/11.txt && diff -w test-io/expected-output-files/11.txt test-io/output-files/11.txt`

#### Public Test 12:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/12.txt > test-io/output-files/12.txt && diff -w test-io/expected-output-files/12.txt test-io/output-files/12.txt`

#### Public Test 13:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/13.txt > test-io/output-files/13.txt && diff -w test-io/expected-output-files/13.txt test-io/output-files/13.txt`

#### Public Test 14:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/14.txt > test-io/output-files/14.txt && diff -w test-io/expected-output-files/14.txt test-io/output-files/14.txt`

#### Public Test 15:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/15.txt > test-io/output-files/15.txt && diff -w test-io/expected-output-files/15.txt test-io/output-files/15.txt`

#### Public Test 16:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/16.txt > test-io/output-files/16.txt && diff -w test-io/expected-output-files/16.txt test-io/output-files/16.txt`

#### Public Test 17:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/17.txt > test-io/output-files/17.txt && diff -w test-io/expected-output-files/17.txt test-io/output-files/17.txt`

#### Public Test 18:

`g++ -std=c++14 -Werror -Wuninitialized -o build/test_io src/main.cpp && build/test_io < test-io/input-files/18.txt > test-io/output-files/18.txt && diff -w test-io/expected-output-files/18.txt test-io/output-files/18.txt`
