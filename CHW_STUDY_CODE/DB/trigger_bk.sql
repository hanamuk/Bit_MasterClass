--트리거를 이용한 복제구현(동기화 구현)
create table dept_bk as select * from dept;

-- dept table에 insert 가 발생하면 dept_bk table에 insert가 발생(백업같은)
create or replace trigger t_dept_in
	after insert or delete or update on dept
	for each row
begin
	if inserting then
		insert into dept_bk values(:new.deptno, :new.dname, :new.loc);
	elsif deleting then
		--insert into dept_bk values(:old.deptno, :old.dname, :old.loc);
		delete from dept_bk where deptno = :old.deptno;
	elsif updating then
		--insert into dept_bk values(:new.deptno, :new.dname, :new.loc);
		update dept_bk set deptno = :new.deptno,dname  = :new.dname, loc = :new.loc where deptno = :old.deptno;
	end if;
end;
/


--입력된 테이블의 행의 컬럼값을 지칭하는 키워드는 : [:new.컬럼명]
--삭제된 테이블의 행의 컬럼값 : [:old.컬럼명]