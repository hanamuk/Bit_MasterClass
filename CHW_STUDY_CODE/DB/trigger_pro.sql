
-- dept table�� insert �� �߻��ϸ� dept_bk table�� insert�� �߻�(�������)
create or replace trigger t_emp_in
	after insert or delete or update on loan
	for each row
begin
	if inserting then
		update emp set  loan_ck ='Y' where  empid = :new.eid;
	elsif deleting then
		update emp set  loan_ck ='N' where  empid = :old.eid;
		
	elsif updating then
		update  emp set  loan_ck ='N' where    empid = :old.eid;
		update  emp set  loan_ck ='Y'  where  empid = :new.eid;
	end if;
end;
/


--�Էµ� ���̺��� ���� �÷����� ��Ī�ϴ� Ű����� : [:new.�÷���]
--������ ���̺��� ���� �÷��� : [:old.�÷���]