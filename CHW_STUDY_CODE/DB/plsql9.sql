
--학생 테이블의 데이터를 기준으로 총점, 평균, 학점(수,..), 평가(70이상 합격), 석차 계산하여
--성적표에 입력하는 커서를 정의
declare
	cursor stud is select hakbun, name, kor, mat, eng from student;
	n_tot record.total%type;
	n_ave record.ave%type;
	v_hak record.hakjum%type;
	v_gra record.grade%type;
begin
	for i in stud loop
		n_tot := i.kor+ i.mat+ i.eng;
		n_ave := n_tot/3;
		
 		if n_ave >90 then
      		 	v_hak :='4';
   		elsif n_ave >80 then
      			v_hak :='3';
  		 else
     		 	v_hak :='0';
  		 end if;


		if n_ave >90 then
      		 	v_gra  :='A';
   		elsif n_ave >80 then
      			v_gra  :='B';
  		 else
     		 	v_gra :='C';
  		 end if;

		insert into record values(i.hakbun, i.name,i.kor, i.mat, i.eng, n_tot, n_ave, v_hak, v_gra, 0  );
	end loop;


	declare
		cursor rak is select ave, hakbun from record;
		v_rank record.s_rank%type;
	begin
		for i in rak loop
		select count(s_rank)+1 into v_rank  from record where i.ave < ave;
		update record set s_rank = v_rank where i.hakbun = hakbun;
		end loop;
	end;

end;
/
