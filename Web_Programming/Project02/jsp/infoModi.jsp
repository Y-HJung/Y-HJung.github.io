<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<jsp:useBean id="dto" class="customer.CustomerDTO" scope="session"/>
<jsp:useBean id="dao" class="customer.CustomerDAO"/>
<link rel="stylesheet" href="../css/info_modi.css">
<link href="https://fonts.googleapis.com/css2?family=Praise&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Nanum+Gothic&display=swap" rel="stylesheet">
<title>회원정보 수정</title>
<script src="https://kit.fontawesome.com/1b5a5bad3c.js" crossorigin="anonymous"></script>
<script defer src="../js/info_modi.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>
<body>
<%
String id = dto.getId();
String pw = request.getParameter("passwd");
String name = dao.checkName(id);
String tel = dao.checkTel(id);
System.out.println(id);
boolean flag = dto.isVerified();
if(!flag) {
%>
<script>alert("잘못된 접근입니다."); location.href="../index.html";</script>
<% } else {
		if(dao.checkIdPwd(id, pw)) {
%>
<div class="container">
    <header>
      <div class="logo">
        <span><a href="./loginSuc_main.jsp">HyeJung</a></span>
      </div>
    </header>
    <div class="join">
      <form action="./infoModi_reg.jsp" method="post">
        <div class="join_idpw">
          <div class="id">
            <span class="text">아이디</span>
            <input id="id_input" type="text" value="<%=id %>" disabled>
          </div>
          <div class="pw">
            <span class="text">비밀번호</span>
            <input id="pw_input" type="password" name="passwd" value="<%=pw %>">
            <i class="far fa-eye-slash"></i>
          </div>
          <span class="error">필수 정보입니다.</span>
          <div class="pw_check">
            <span class="text">비밀번호 확인</span>
            <input id="pwCheck_input" type="password">
            <i class="far fa-eye-slash"></i>
          </div>
          <span class="error">필수 정보입니다.</span>
          <span class="pw_error">비밀번호가 일치하지 않습니다.</span>
        </div>
        <div class="join_info">
          <div class="name">
            <span class="text">이름</span>
            <input type="text" id="name_input" name="name" value="<%=name%>">
          </div>
          <span class="error">필수 정보입니다.</span>
          <div class="mobile">
            <span class="text">휴대전화</span>
            <input type="tel" id="tel_input" name="tel" value="<%=tel%>">
          </div>
          <span class="error">필수 정보입니다.</span>
        </div>
        <div class="join_btn">
          <button type="button" class="btn">
            <span class="btn_text">수정하기</span>
          </button>
        </div>
      </form>
    </div>
  </div>
<%
	}
	else {
%>
<script>alert("비밀번호가 일치하지 않습니다."); location.href="./pwCheck.jsp";</script>
<%
	}
}
%>
</body>
</html>
