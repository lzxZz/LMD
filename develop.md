<style>
    #mid{
        float:left;
        text-align:center;
        width:100%;
    },
    .mermaid{
         float:left;
        text-align:center;
        width:100%;
    }
</style>
# �����޸�
����`lmd`�ļ���ʹ��`document`���`content`�洢���ı����ݣ���`parse`�����У�һ��������ǩ�ַ���`vector<term>`�У�֮��ݹ�ĵ��ø�����ǩ��`setcontent`�����洢���ݣ���ʹ��`parse`����ת��Ϊhtml��


> ����ĵ�

# ��Ҫ���

* ����˼·������DOM��������һ��ǿ������ת����

����һ��lmd�ĵ���ʹ��һ��`document`�ڵ�����������������Ϊ`section`�ڵ㣬`section`�а�����`content`�ڵ㡣`content`�ڵ���������е�ʵ�����ݣ��̳���`InnerTerm`
���е�`section`�ڵ�̳���`SectionTerm`��һ���ࡣ

<span id="mid">ͼ1 �ڵ�̳й�ϵ</span>
```mermaid
graph TD;
Term-->SectionTerm
Term-->DocumentTerm
Term-->InnerTerm
```




****
**׷���﷨1�������ڱ�񣬴������⣬���еĿ��ж���ʾһ������Ľ���**
****

## ����Ϊ������ֵı�ǩ��
1. ����
    ������־����β����
2. �б�
    ������־��ͬ�������Ŀ���
3. ����
    ������־:���У������ڿ���ʹ����β��ӵ�`\\`���з���
4. �ָ���
    ������־����β����
5. ͼƬ
    ������־����ǩβ������
6. �����
    ������־��ƥ���` ``` `
7. ���
    ��ʼ��`\btab`������`etab`
8. ��ѧ��ʽ
    ��ʼ��`$$`�����������`$$`
8. ��ͨ�ı�
    > ע�����е�ʣ�µı�ǩ������Ϊ��ͨ�ı���֧��
    ������־:���С�


<span id="mid">ͼ2 ����ڵ�̳й�ϵ</span>

```mermaid
graph TD;
SectionTerm-->TitleTerm
SectionTerm-->ListTerm
SectionTerm-->QuotTerm
SectionTerm-->SplitTerm
SectionTerm-->ImageTerm
SectionTerm-->CodesTerm
SectionTerm-->TableTerm
SectionTerm-->MathTerm
SectionTerm-->CotentTerm
```

## �ڲ�������ʽ
1. ָ������
    \cls{names}{content}
2. ������
3. �Ӵ�
4. б��
5. ������ѧ��ʽ
6. ���ڴ���
7. ê��(��ϳ�����ʵ��ҳ����ת)
8. �޸�ʽ�ı�

<span id="mid">ͼ3 �ڲ�Ԫ�ؼ̳й�ϵ</span>

```mermaid
graph TD

InnerTerm --> ClassTerm
InnerTerm --> LinkTerm
InnerTerm --> BoldTerm
InnerTerm --> ItalyTerm
InnerTerm --> InnerMathTerm
InnerTerm --> InnerCodeTerm
InnerTerm --> LabelTerm
InnerTerm --> PlaintextTerm
```

# ��ϸ��� 
Ϊ�˸���Ԫ�ص���Ϊ�߶�һ�£��������еķ���ȫ�����󵽸����У�����ʵ����Щ�������ɡ�Ϊ�˷������ʹ���Ե����ϵķ�����������Ϊ��
## ����Ԫ������
### 0. ����Ԫ��
* ���Ա
    * String Grammer: `[\s\S]*?`
    * vector<InnerTerm> 

### 1. ָ������
* ���Ա
    * String Grammer: `\\cls\{.+?\}\{.*?\}`
        ������ʽ
    * DocumentTerm Content:
        �ڲ��ı�������֧�����е�Ԫ���﷨������ʹ���ĵ�Ԫ��������������ı���
    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��

### 2. ������
* ���Ա
     * String Grammer: `\[.+?\]\(.+?\)` ���� `\\link\{.+?\}\{.+?\}`
        ������ʽ
    * String src:
        �����ӵ�ַ
    * InnerTerm alt:
        �������ı�

    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��

### 3. �Ӵ�
* ���Ա
     * String Grammer: `\[\*\-\+\]{2}.+?\[\*\-\+\]{2}`
        ������ʽ
    * InnerTerm Content:
        Ҫ�Ӵ���ʾ�����ݡ�
    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��

### 4. б��
* ���Ա
    * String Grammer: `\[\*\-\+\].+?\[\*\-\+\]`
        ������ʽ
    * InnerTerm Content:
        Ҫб����ʾ�����ݡ�
    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��
    
### 5. ������ѧ��ʽ
* ���Ա
    * String Grammer: `\$.+?\$`
        ������ʽ
    * String Content:
        Ҫ��ʾΪ��ѧ��ʽ�����ݡ�
    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��(ԭ��������ɣ�Mathjax����ת��)
    
### 6. ���ڴ���
* ���Ա
    * String Grammer: ` `.+?` `
        ������ʽ
    * String Content:
        Ҫ��ʾ�����ݡ�
    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��
    
### 7. ê��
* ���Ա
    * String Grammer: `\\lb\{.+?\}`
        ������ʽ
    * String Content:
        Ҫ�Ӵ���ʾ�����ݡ�
    * void SetContent()
        �����ڲ��ı�
    * String ParsingToHtml()
        ���ڲ��ı�ת��ΪHTML��ǩ��
    
### 8.�޸�ʽ�ı�
* ���Ա
    * string content;
        �ڲ��ı�
    * void SetContent()
        �����ڲ��ı�
    * string ParsingToHtml()
        ԭ���������

## ����Ԫ�ظ�ʽ
```
SectionTerm-->TitleTerm
SectionTerm-->ListTerm
SectionTerm-->QuotTerm
SectionTerm-->SplitTerm
SectionTerm-->ImageTerm
SectionTerm-->CodesTerm
SectionTerm-->TableTerm
SectionTerm-->MathTerm
SectionTerm-->CotentTerm
```
### 1. �����ʽ
* ���Ա
    * string Grammar : `\#{1,6} .+` ��`\\t[1-6]\{.+?\}`
        ������ʽ
    * string content
        �ڲ��ı�����
    * bool IsCrossLine = false
        �Ƿ�Ϊ�����ı�
    * 
### 2. �б��ʽ
### 3. ���ø�ʽ
### 4. �ָ���
### 5. ͼƬ
### 6. �����
### 7. ���
### 8. ��ѧ��ʽ
### 9. �ı���  

## ���������
* InnerTerm
���г�Ա
    * private string Content
    * public void setContent()
    * public string ParsingToHtml()







