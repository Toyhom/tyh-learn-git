# gitѧϰ�ʼ�


$ mkdir learngit
$ cd learngit
$ pwd

$ git init

$ git add readme.txt                                     ���
$ git commit -m "wrote a readme file"         �ύ


$ git status       �ֿ�״̬   ���ύ   ���ύ   �ļ��Ƿ��޸�
$ git diff readme.txt


$ git log  �汾��¼
$ git reset --hard HEAD^  �汾����
$ git reset --hard 1094a
$ git reflog   �����¼

git diff HEAD -- readme.txt   �鿴�������Ͱ汾���������°汾������


����git checkout -- readme.txt��˼���ǣ���readme.txt�ļ��ڹ��������޸�ȫ�����������������������
һ����readme.txt���޸ĺ�û�б��ŵ��ݴ��������ڣ������޸ľͻص��Ͱ汾��һģһ����״̬��
һ����readme.txt�Ѿ���ӵ��ݴ������������޸ģ����ڣ������޸ľͻص���ӵ��ݴ������״̬��
  ��֮������������ļ��ص����һ��git commit��git addʱ��״̬��


$ git reset HEAD <file> ����ݴ���

��or create a new repository on the command line
echo "# tyh-learn-git" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:Toyhom/tyh-learn-git.git  �����
git push -u origin master   ϵͳ����

$ git push origin master  

$ git clone git@github.com:michaelliao/gitskills.git   ��¡

