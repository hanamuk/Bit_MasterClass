-- ����� �޿��� �����ϸ�. ***
-- 1. ���� �޼��� ���(�޿��� ������ �� ������!)
-- 2. ������ ���Ǹ�, ��¥(�ð�����), ��������ȣ, ������ �ݾ�, ������ �ݾ� ������ black_list ���̺� �Է�(black_list ���̺� ����)
--    ����> �޿��� ����Ұ� + ��� 
-- 3. �����Ϸ��� �޿� �ݾ��� �����޿����� ���ų� �����޿��� 10%�� �ʰ��ϸ� ���� ���
-- 4. 3�������� ��, ��å�� ������ ����

-- raise_application_error(������ȣ, '�޼���');      // rollback ����, ���α׷� ���� ����
--              20001~20999, '2048Byte'

create table black_list(username varchar2(10) default user, event_date varchar2(20) default to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss'),
         sabun number(3), 
         sapay number(10), upsapay number(10));

create or replace trigger t_gogek_insert
      before update of sapay on sawon
      for each row
      when (new.sajob != '����')

declare
   PRAGMA AUTONOMOUS_TRANSACTION;
begin
  -- insert into black_list(sabun, sapay, upsapay) values(:new.sabun, :old.sapay, :new.sapay);
  -- commit;
  -- raise_application_error(-20001, '�޿��� ������ �� ����!!');

	then
    	 if (:new.sapay < :old.sapay) OR (:new.sapay > :old.sapay * 1.1)
    	 then  raise_application_error(-20002, '�����޿����� �۰ų�, �λ� �ѵ����ʰ��մϴ�.');
 	 end if;


end;
/