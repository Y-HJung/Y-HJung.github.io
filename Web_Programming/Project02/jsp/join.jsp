<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>회원가입 등록</title>
<jsp:useBean id="dto" class="customer.CustomerDTO"/>
<jsp:setProperty name="dto" property="*" />
<jsp:useBean id="dao" class="customer.CustomerDAO"/>
</head>
<body>
<%
int rec_no = dao.insertCustomer(dto.getId(), dto.getPasswd(), dto.getName(), dto.getGender(), dto.getTel());
if(rec_no > 0) {
%>
<script>alert("회원가입을 환영합니다"); location.href="../index.html";</script>
<% } %>
</body>
</html>
