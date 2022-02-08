<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<jsp:useBean id="dto" class="customer.CustomerDTO" scope="session"/>
<jsp:useBean id="dao" class="customer.CustomerDAO"/>
<link rel="stylesheet" href="../css/pwCheck.css">
<link href="https://fonts.googleapis.com/css2?family=Praise&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Nanum+Gothic&display=swap" rel="stylesheet">
<title>비밀번호 확인</title>
<script src="https://kit.fontawesome.com/1b5a5bad3c.js" crossorigin="anonymous"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script defer src="../js/pwCheck.js"></script>
</head>
<body>
<%
String id = dto.getId();
System.out.println(id);
boolean flag = dto.isVerified();
if(!flag) {
%>
<script>alert("잘못된 접근입니다."); location.href="../index.html";</script>
<% } else {
%>
<div class="container">
    <header>
      <div class="logo">
        <span><a href="./loginSuc_main.jsp">HyeJung</a></span>
      </div>
    </header>
    <div class="content">
      <div class="login">
        <div class="id">
            <div class="userId">
              <h2>회원 비밀번호 확인</h2>
              <div class="id_info">아이디: <span class="id_color"><%=id %></span></div>
            </div>
          </div>
        <form action="./infoModi.jsp" method="post">
          <div class="passwd">
            <input id="pw_check" type="password" name="passwd" placeholder="비밀번호" autofocus>
            <div class="pw_icon">
              <i class="fas fa-lock"></i>
            </div>
            <div class="pw_delBtn">
              <i class="fas fa-times-circle"></i>
            </div>
          </div>
          <div class="pw_show">
            <input id="show" type="checkbox">
            <span>비밀번호 표시</span>
          </div>
          <span class="pw_error">비밀번호를 입력해 주세요.</span>
          <div class="login_btn">
            <button type="button" class="btn">
              <span class="btn_text">확인하기</span>
            </button>
          </div>
        </form>
      </div>
    </div>
  </div>
<% } %>
</body>
</html>
