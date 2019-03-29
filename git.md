# git学习笔记


$ mkdir learngit
$ cd learngit
$ pwd

$ git init

$ git add readme.txt                                     添加
$ git commit -m "wrote a readme file"         提交


$ git status       仓库状态   待提交   无提交   文件是否被修改
$ git diff readme.txt


$ git log  版本记录
$ git reset --hard HEAD^  版本回退
$ git reset --hard 1094a
$ git reflog   命令记录

git diff HEAD -- readme.txt   查看工作区和版本库里面最新版本的区别


命令git checkout -- readme.txt意思就是，把readme.txt文件在工作区的修改全部撤销，这里有两种情况：
一种是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；
一种是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。
  总之，就是让这个文件回到最近一次git commit或git add时的状态。


$ git reset HEAD <file> 清空暂存区

…or create a new repository on the command line
echo "# tyh-learn-git" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:Toyhom/tyh-learn-git.git  库关联
git push -u origin master   系统关联

$ git push origin master  

$ git clone git@github.com:michaelliao/gitskills.git   克隆

