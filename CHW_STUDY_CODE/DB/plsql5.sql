--�Է¹��� �����ȣ�� ��� Ŀ�̼��� �����ϴ� ���α׷�(���̺� comm n(10) �÷� �߰� �� �۾�)
--��, Ŀ�̼��� �޿��� 1000�̸�   -> �޿��� 10%
                --1000 ~ 2000    -> �޿��� 15%
         --2000�ʰ�   -> �޿��� 20%
         --null   -> 0

set serveroutput on
set verify off

--alter table sawon add comm number (10);

accept num prompt '���ڸ� �Է� -> '

declare
   name sawon.saname%type;
   comm sawon.sapay%type;
begin
   select saname, sapay into name, comm from sawon where sabun = &num;
   if comm < 1000 then
      comm := comm*1.1;
   elsif comm < 2000 then
      comm := comm*1.15;
   elsif comm > 2000 then
      comm := comm*1.2;
   end if;
   dbms_output.put_line(name || ' Ŀ�̼� : ' || comm);
end;
/
