这是我无聊的时候做的辣鸡评测机。

目前的功能：评测多选手的多题代码是否正确。目前仅能判断"Accept""Wrong Answer"和测量程序运行时间(与电脑CPU占用等是有关的)。

我会慢慢把它完善的。

下面是使用说明：

在testsettings.txt里按顺序填入以下信息

一个正整数n表示选手个数
接下来n行，每行一个字符串表示这个选手的代号(名)
一个正整数q表示题目个数
接下来(4\*q)行，每4\*q行的内容如下：
第一行是该题的题目名
第二行是数据组范围
第三行是程序输出文件的后缀
第四行是标准答案文件的后缀



请注意程序输出文件的后缀名不要和标准答案文件的后准名相同

评测使用编译后的exe文件，请源代码不要带文件输入输出

评测的文件为Test.exe
Judger.exe是测单点结果的程序
最后成绩会导出到Final.txt里

整个包已经放了个样本，可自行研究。
