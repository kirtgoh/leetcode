Leetcode
--------

This is my solutions to [LeetCode Online Judge](https://oj.leetcode.com)'s
problems, and a test environment based on [Google
Test](https://code.google.com/p/googletest/) framework is also configed.  Backed
datastructures are wrapped so that you can init and config test cases easily,
leaving you more time to focus on challenging and interesting problems.  Feel
free to submit pull requests for bug reports or solution suggestions. Enjoy it!

### Compiling
If you don't have SCons install, install it using your stanard application
installation program like apt-get or yum. Once you have SCons install go to
Leetcode directory and give following command:

    $ scons -Q 

To clean your compilation:

    $ scons -Q -c

### Running
After successfull compilation, to run Leetcode you have to be in the root of
Leetcode source directory.  Then give the following command:

    $ ./leetcode

### Contact
If you have bug reports or feature suggestions, please use the issue tracker.

### License
[MIT](http://cgm.mit-license.org/) © 2014 Kirt Goh
