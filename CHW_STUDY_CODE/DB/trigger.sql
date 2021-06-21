
create or replace trigger t_dept_ex
	after delete on dept_ex
	for each row
begin 
	insert into dept_info values('부서삭제');

end;
/
