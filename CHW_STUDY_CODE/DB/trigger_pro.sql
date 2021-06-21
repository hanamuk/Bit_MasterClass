
-- dept table에 insert 가 발생하면 dept_bk table에 insert가 발생(백업같은)
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


--입력된 테이블의 행의 컬럼값을 지칭하는 키워드는 : [:new.컬럼명]
--삭제된 테이블의 행의 컬럼값 : [:old.컬럼명]