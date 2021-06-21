--update cascade 구현
-- 부서테이블에 부서번호가 변경되면 사원테이블의  그부서를 참조하는 사원들의 부서번호도 함께 변경
create or replace trigger sawon_up_cas
	after update of deptno on dept
	for each row

begin
	update sawon set deptno = :new.deptno where deptno = :old.deptno;
end;
/
