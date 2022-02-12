package hello.hellospring.controller;
import hello.hellospring.domain.Member;
import hello.hellospring.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
public class MemberController {

    private final MemberService memberService;

    @Autowired
    //생성자 주입(권장)
    public MemberController(MemberService memberService)
    {
        this.memberService = memberService;
    }

    @GetMapping(value = "/members/new") //home.html의 회원가입 위치
    public String createForm() {
        return "members/createMemberForm"; //이 html로 이동
    }

    @PostMapping(value = "/members/new")
    public String create(MemberForm form) { //직접 등록한 spring 값 들어옴

        Member member = new Member();
        member.setName(form.getName());

        memberService.join(member);

        return "redirect:/"; //다시 돌아옴
    }

    @GetMapping(value = "/members")
    public String list(Model model) {

        List<Member> members = memberService.findMembers(); //member 전체 다 가지고 옴
        model.addAttribute("members", members);
        
        return "members/memberList";
    }
}