(() => {
  'use strict';

  const $ = (selector, context = document) => context.querySelector(selector);
  const $$ = (selector, context = document) => Array.from(context.querySelectorAll(selector));

  const icon = (name, extra = '') => `<svg class="icon ${extra}" aria-hidden="true"><use href="#i-${name}"/></svg>`;

  const escapeHTML = (value = '') => String(value)
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
    .replace(/"/g, '&quot;')
    .replace(/'/g, '&#039;');

  const formatMoney = (value) => Number(value || 0).toLocaleString('zh-CN', {
    minimumFractionDigits: 2,
    maximumFractionDigits: 2
  });

  const pageTitles = {
    dashboard: '工作台',
    jobs: '岗位样本',
    merchant: '商家自检',
    profile: '个人画像',
    wallet: '薪资存证',
    compliance: '合规检测',
    rights: '快捷维权',
    relief: '被骗救济'
  };

  const jobs = [
    {
      id: 'job-1',
      title: '周末咖啡店店员',
      merchant: 'M Stand 咖啡',
      category: '门店服务',
      pay: '200',
      unit: '元/天',
      paySort: 200,
      settlement: '日结',
      location: '济南 · 历下',
      area: '历下',
      distance: '距你 2.4km',
      schedule: '周六日 10:00-18:00',
      tags: ['包午餐', '地铁周边', '可连做'],
      description: '负责门店点单、饮品制作辅助、取餐区整理与顾客接待。门店氛围轻松，提供完整岗前培训，无需咖啡经验。',
      requirements: ['有服务意识，沟通自然', '可连续工作 4 个周末', '持健康证或可在入职前办理'],
      highlight: '商家已提交认证材料 · 薪资约定可存证'
    },
    {
      id: 'job-2',
      title: '校园新媒体运营',
      merchant: '知行教育工作室',
      category: '内容创作',
      pay: '150',
      unit: '元/天',
      paySort: 150,
      settlement: '周结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '每周 3 天 · 时间灵活',
      tags: ['远程', '作品集加分', '长期'],
      description: '运营校园新媒体账号，完成选题策划、图文编辑与社群互动。每周提交内容排期，数据表现优秀另有奖励。',
      requirements: ['熟悉小红书 / 公众号内容生态', '具备基础图片编辑能力', '每周可投入 12 小时以上'],
      highlight: '线上签约 · 周结金额可记录存证'
    },
    {
      id: 'job-3',
      title: '展会双语引导',
      merchant: '山东澜图会展',
      category: '活动执行',
      pay: '260',
      unit: '元/天',
      paySort: 260,
      settlement: '日结',
      location: '济南 · 山东国际会展中心',
      area: '槐荫',
      distance: '地铁直达会展中心',
      schedule: '11 月 12 日-14 日 08:30-17:30',
      tags: ['英语口语', '提供工作餐', '三天连做'],
      description: '负责展会入口引导、嘉宾接待与双语咨询，协助现场秩序维护。活动前提供统一培训与工作证件。',
      requirements: ['英语口语流利，CET-6 优先', '形象大方，有展会经验优先', '可完成三天连续工作'],
      highlight: '活动信息样本 · 结算条款待核验'
    },
    {
      id: 'job-4',
      title: '数据标注实习生',
      merchant: '云粒科技',
      category: '线上兼职',
      pay: '30',
      unit: '元/小时',
      paySort: 30,
      settlement: '月结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '每周 10-15 小时 · 自由排班',
      tags: ['远程', '技能培训', '实习证明'],
      description: '根据标注规范完成图像与文本数据整理，协助质检样本。任务按批次发放，提供线上培训与答疑支持。',
      requirements: ['耐心细致，能长期参与', '自备电脑与稳定网络', '每周至少完成 10 小时'],
      highlight: '企业已提交认证材料 · 金额与结算方式待确认'
    },
    {
      id: 'job-5',
      title: '晚托班辅导老师',
      merchant: '小树成长中心',
      category: '教育培训',
      pay: '80',
      unit: '元/小时',
      paySort: 80,
      settlement: '周结',
      location: '济南 · 高新区',
      area: '高新区',
      distance: '距你 5.1km',
      schedule: '工作日 16:30-19:30',
      tags: ['师范优先', '周结', '提供晚餐'],
      description: '辅导小学阶段学生完成课后作业，维持课堂秩序，并与家长进行简单反馈。每班不超过 8 名学生。',
      requirements: ['本科在读，师范专业优先', '有耐心，善于与孩子沟通', '每周至少到岗 3 天'],
      highlight: '办学材料已提交 · 认证仅为形式核验'
    },
    {
      id: 'job-6',
      title: '宠物店周末助理',
      merchant: '毛球研究所',
      category: '门店服务',
      pay: '180',
      unit: '元/天',
      paySort: 180,
      settlement: '日结',
      location: '济南 · 槐荫',
      area: '槐荫',
      distance: '距你 4.8km',
      schedule: '周六日 11:00-19:00',
      tags: ['宠物友好', '日结', '可撸猫'],
      description: '协助完成宠物洗护区清理、用品整理与顾客接待，不涉及专业洗护操作。店内有猫，需对宠物毛发不过敏。',
      requirements: ['喜欢小动物，不怕猫狗', '可接受站立工作', '周末可稳定到岗'],
      highlight: '工时记录可留痕 · 结算条款待确认'
    },
    {
      id: 'job-7',
      title: '短视频剪辑',
      merchant: '野芒内容实验室',
      category: '内容创作',
      pay: '300',
      unit: '元/条',
      paySort: 300,
      settlement: '项目结',
      location: '线上 · 远程',
      area: '线上',
      distance: '远程办公',
      schedule: '按项目交付 · 时间自由',
      tags: ['远程', '按条结算', '可长期合作'],
      description: '根据脚本完成 60 秒以内短视频剪辑，包含基础字幕、节奏卡点与封面制作。试稿通过后进入长期合作池。',
      requirements: ['熟练使用剪映 / PR', '有短视频作品可展示', '能在约定时间内交付'],
      highlight: '项目合同 · 验收后按约定记录结算'
    },
    {
      id: 'job-8',
      title: '超市理货员',
      merchant: '邻家生活超市',
      category: '门店服务',
      pay: '22',
      unit: '元/小时',
      paySort: 22,
      settlement: '日结',
      location: '济南 · 长清大学城',
      area: '长清',
      distance: '距你 3.2km',
      schedule: '可排班 · 每次 4 小时起',
      tags: ['排班灵活', '就近安排', '日结'],
      description: '负责货架商品整理、价签核对与简单库存盘点，协助高峰时段的顾客引导。工作强度适中。',
      requirements: ['认真负责，能接受站立工作', '每周可排班 2 次以上', '可长期兼职优先'],
      highlight: '门店用工样本 · 工时记录可留痕'
    }
  ];

  const sampleRisks = {
    'job-1': [
      { level: 'high', label: '薪资条款缺失' },
      { level: 'medium', label: '无书面合同' }
    ],
    'job-2': [
      { level: 'medium', label: '结算周期不明确' },
      { level: 'medium', label: '知识产权归属缺失' }
    ],
    'job-3': [
      { level: 'high', label: '无书面协议' },
      { level: 'medium', label: '超时补偿不明' }
    ],
    'job-4': [
      { level: 'high', label: '薪资计算口径不清' },
      { level: 'medium', label: '验收标准缺失' }
    ],
    'job-5': [
      { level: 'medium', label: '安全保障未约定' },
      { level: 'medium', label: '试用期待遇缺失' }
    ],
    'job-6': [
      { level: 'high', label: '意外责任未约定' },
      { level: 'medium', label: '无书面合同' }
    ],
    'job-7': [
      { level: 'medium', label: '验收标准不明确' },
      { level: 'medium', label: '版权归属不清' }
    ],
    'job-8': [
      { level: 'medium', label: '工时记录方式不明' },
      { level: 'medium', label: '休息时间未列明' }
    ]
  };

  const sampleMeta = {
    'job-1': { logo: 'M', logoClass: 'logo-mstand' },
    'job-2': { logo: '知', logoClass: 'logo-blue' },
    'job-3': { logo: '澜', logoClass: 'logo-coral' },
    'job-4': { logo: '云', logoClass: 'logo-purple' },
    'job-5': { logo: '树', logoClass: 'logo-sand' },
    'job-6': { logo: '毛', logoClass: 'logo-coral' },
    'job-7': { logo: '野', logoClass: 'logo-purple' },
    'job-8': { logo: '邻', logoClass: 'logo-blue' }
  };

  jobs.forEach((job, index) => {
    Object.assign(job, sampleMeta[job.id] || {});
    job.risks = sampleRisks[job.id] || [];
    job.detected = `10 月 ${18 - Math.floor(index / 2)} 日`;
  });

  const initialTransactions = [
    { type: 'in', title: '校园新媒体运营 · 周结', meta: '10 月 18 日 14:32 · 双方确认已线下结算', amount: 450, status: '已确认' },
    { type: 'in', title: 'M Stand 咖啡 · 日结', meta: '10 月 17 日 19:05 · 双方确认已线下结算', amount: 200, status: '已确认' },
    { type: 'in', title: '展会双语引导 · 日结', meta: '10 月 12 日 18:40 · 双方确认已线下结算', amount: 520, status: '已确认' },
    { type: 'in', title: '宠物店周末助理 · 日结', meta: '10 月 11 日 20:10 · 双方确认已线下结算', amount: 180, status: '已确认' },
    { type: 'in', title: '短视频剪辑 · 项目结', meta: '10 月 9 日 09:30 · 验收记录已存证', amount: 300, status: '待确认' },
    { type: 'in', title: '超市理货员 · 日结', meta: '10 月 8 日 20:15 · 待商家确认结算', amount: 88, status: '待结算' }
  ];

  const initialMerchantJobs = [
    { id: 'pos-1', title: '周末咖啡店店员', meta: '济南 · 历下 · 周六日', pay: '200 元/天', settlement: '日结', riskCount: 2, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-2', title: '品牌快闪店店员', meta: '济南 · 槐荫 · 11 月档期', pay: '260 元/天', settlement: '日结', riskCount: 1, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-3', title: '咖啡师学徒', meta: '济南 · 历下 · 每周 3 天', pay: '30 元/小时', settlement: '周结', riskCount: 2, status: 'pending', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-4', title: '门店社群运营', meta: '线上 · 每周 8 小时', pay: '120 元/天', settlement: '周结', riskCount: 0, status: 'active', logo: 'M', logoClass: 'logo-mstand' },
    { id: 'pos-5', title: '秋季校园大使', meta: '多校区 · 项目制', pay: '150 元/天', settlement: '项目结', riskCount: 1, status: 'closed', logo: 'M', logoClass: 'logo-mstand' }
  ];

  const initialReliefHistory = [
    { id: 'AJ202609280126', type: '押金 / 保证金诈骗', amount: '¥199.00', status: '援助中', date: '2026-09-28' }
  ];

  const state = {
    category: '全部',
    search: '',
    location: 'all',
    sort: 'recommend',
    walletBalance: 1840,
    transactions: initialTransactions.slice(),
    merchantJobs: initialMerchantJobs.slice(),
    reliefStep: 1,
    scanTimers: []
  };

  function showToast(message, kind = 'success') {
    const container = $('#toastContainer');
    if (!container) return;
    const toast = document.createElement('div');
    toast.className = 'toast';
    toast.innerHTML = `${icon(kind === 'error' ? 'alert' : kind === 'info' ? 'info' : 'check-circle')}<span>${escapeHTML(message)}</span>`;
    container.appendChild(toast);
    window.setTimeout(() => {
      toast.classList.add('leaving');
      window.setTimeout(() => toast.remove(), 300);
    }, 3200);
  }

  function renderJobCard(job) {
    const highCount = job.risks.filter((risk) => risk.level === 'high').length;
    return `
      <article class="job-card sample-card" data-job-id="${escapeHTML(job.id)}" tabindex="0" role="button" aria-label="查看岗位风险样本：${escapeHTML(job.title)}">
        <div class="job-card-head">
          <div class="merchant-line">
            <span class="merchant-logo ${escapeHTML(job.logoClass || '')}">${escapeHTML(job.logo || job.merchant.slice(0, 1))}</span>
            <div>
              <strong>${escapeHTML(job.merchant)}</strong>
              <span class="merchant-verified">${icon('check-circle')}已核验</span>
            </div>
          </div>
          <span class="sample-badge">待检岗位示例</span>
        </div>
        <div class="job-card-body">
          <div class="job-title-row">
            <h3>${escapeHTML(job.title)}</h3>
            <span class="sample-risk-count">风险项 ${job.risks.length} 个</span>
          </div>
          <div class="job-risk-chips">
            ${job.risks.map((risk) => `<span class="risk-chip ${risk.level}"><i></i>${escapeHTML(risk.label)}</span>`).join('')}
          </div>
        </div>
        <div class="job-meta">
          <span>${icon('map-pin')}${escapeHTML(job.location)}</span>
          <span>${icon('file')}检测于 ${escapeHTML(job.detected)}</span>
        </div>
        <div class="job-card-foot">
          <span class="sample-footnote">${highCount ? `${highCount} 项高风险提示` : '暂无高风险提示'} · 仅展示检测结果</span>
          <span class="sample-report-link">查看风险报告 ${icon('arrow-right')}</span>
        </div>
      </article>
    `;
  }

  function filteredJobs() {
    let list = jobs.filter((job) => {
      const keyword = state.search.trim().toLowerCase();
      const matchesKeyword = !keyword || [job.title, job.merchant, job.category, job.location, job.description, ...job.tags, ...job.risks.map((risk) => risk.label)]
        .join(' ')
        .toLowerCase()
        .includes(keyword);
      const matchesCategory = state.category === '全部' || job.category === state.category;
      const matchesLocation = state.location === 'all' || job.area === state.location;
      return matchesKeyword && matchesCategory && matchesLocation;
    });

    if (state.sort === 'risk') {
      const highRiskCount = (job) => job.risks.filter((risk) => risk.level === 'high').length;
      list = list.slice().sort((a, b) => highRiskCount(b) - highRiskCount(a) || b.risks.length - a.risks.length);
    }
    return list;
  }

  function renderJobGrids() {
    const homeGrid = $('#homeJobGrid');
    const jobGrid = $('#jobGrid');
    if (homeGrid) homeGrid.innerHTML = jobs.slice(0, 4).map(renderJobCard).join('');

    const list = filteredJobs();
    if (jobGrid) jobGrid.innerHTML = list.map(renderJobCard).join('');
    const count = $('#jobResultCount');
    if (count) count.textContent = String(list.length);
    const empty = $('#jobEmptyState');
    if (empty) empty.classList.toggle('visible', list.length === 0);
  }

  function openModal(id) {
    const modal = document.getElementById(id);
    if (!modal) return;
    modal.classList.add('open');
    document.body.style.overflow = 'hidden';
  }

  function closeModal(id) {
    const modal = document.getElementById(id);
    if (!modal) return;
    modal.classList.remove('open');
    if (!$('.modal-backdrop.open')) document.body.style.overflow = '';
  }

  function returnHome() {
    $$('.modal-backdrop.open').forEach((modal) => closeModal(modal.id));
    navigate('dashboard');
    window.scrollTo({ top: 0, behavior: 'smooth' });
  }

  function openJobModal(id) {
    const job = jobs.find((item) => item.id === id);
    if (!job) return;
    const content = $('#jobModalContent');
    content.innerHTML = `
      <div class="job-modal-head">
        <div class="job-modal-top">
          <span class="merchant-logo ${escapeHTML(job.logoClass || '')}">${escapeHTML(job.logo)}</span>
          <div class="job-modal-title">
            <div class="merchant-line">
              <div><strong>${escapeHTML(job.merchant)}</strong><span class="merchant-verified">${icon('check-circle')}资质材料已提交 · 形式核验</span></div>
            </div>
            <h2 id="jobModalTitle">${escapeHTML(job.title)}</h2>
            <div class="job-meta">
              <span>${icon('map-pin')}${escapeHTML(job.location)}</span>
              <span>${icon('file')}检测于 ${escapeHTML(job.detected)}</span>
              <span>${icon('alert')}风险项 ${job.risks.length} 个</span>
            </div>
          </div>
          <span class="sample-badge modal-sample-badge">待检岗位示例</span>
        </div>
        <div class="job-modal-badges">
          <span>${icon('file')}仅展示检测结果</span>
          <span>${icon('info')}不提供联系方式</span>
          <span>${icon('lock')}不提供报名或交易入口</span>
        </div>
        <p class="certification-boundary">认证说明：商家认证仅为提交材料的形式核验展示，不代表平台担保岗位真实可靠，请学生自行甄别风险。</p>
      </div>
      <div class="job-modal-body">
        <div>
          <section class="job-modal-section">
            <h3>样本岗位内容</h3>
            <p>${escapeHTML(job.description)}</p>
          </section>
          <section class="job-modal-section">
            <h3>样本中的约定要求</h3>
            <ul>${job.requirements.map((item) => `<li>${escapeHTML(item)}</li>`).join('')}</ul>
          </section>
          <section class="job-modal-section">
            <h3>检测出的风险项</h3>
            <div class="modal-risk-list">
              ${job.risks.map((risk) => `<div class="modal-risk-item ${risk.level}"><span>${risk.level === 'high' ? '高风险隐患' : '中等风险隐患'}</span><strong>${escapeHTML(risk.label)}</strong></div>`).join('')}
            </div>
          </section>
          <div class="sample-disclaimer-inline">
            ${icon('info')}
            <p>本样本仅用于展示岗位风险检测结果，不包含联系方式，也不提供报名、申请或交易入口。</p>
          </div>
        </div>
        <aside class="job-modal-side">
          <div class="job-safety-score">
            <div><span>样本说明</span><strong style="font-size:12px">仅展示检测结果</strong></div>
            <p>平台不对岗位真实性和可靠性作出担保，请自行核实工作内容与结算约定。</p>
          </div>
          <div class="job-safe-checks">
            <span>${icon('file')}商家认证材料仅作形式核验</span>
            <span>${icon('info')}样本不提供任何联系方式</span>
            <span>${icon('alert')}如遇类似风险可提交维权工单</span>
          </div>
          <button class="button button-dark" data-page="compliance">检测我的合同</button>
          <button class="button button-light" data-close-modal="jobModal">返回样本库</button>
          <button class="job-modal-footnote" style="background:none;border:0;padding:0;cursor:pointer;text-align:left" data-toast="如遇权益受损，请前往快捷维权提交工单">${icon('alert')}我有类似问题</button>
        </aside>
      </div>
    `;
    openModal('jobModal');
  }

  function navigate(page) {
    if (!pageTitles[page]) page = 'dashboard';
    if (location.hash === `#${page}`) {
      activatePage(page);
      window.scrollTo({ top: 0, behavior: 'smooth' });
    } else {
      location.hash = page;
    }
  }

  function activatePage(page) {
    if (!pageTitles[page]) page = 'dashboard';
    $$('.page').forEach((section) => section.classList.toggle('active', section.id === `page-${page}`));
    $$('.nav-item').forEach((item) => item.classList.toggle('active', item.dataset.page === page));
    const title = $('#topbarTitle');
    if (title) title.textContent = pageTitles[page];
    document.title = `${pageTitles[page]} · 青薪盾`;
    closeSidebar();
    if (page === 'wallet') renderWallet();
    if (page === 'merchant') {
      renderMerchantJobs();
      switchMerchantTab($('.merchant-panel.active')?.id.replace('merchant-panel-', '') || 'publish');
    }
    if (page === 'relief') renderReliefHistory();
    if (page === 'compliance') {
      window.setTimeout(() => {
        if (!$('#complianceGate')?.classList.contains('open')) openModal('complianceGate');
        $('#acceptComplianceGate')?.focus();
      }, 80);
    } else {
      closeModal('complianceGate');
    }
  }

  function openSidebar() {
    $('#sidebar').classList.add('open');
    $('#sidebarScrim').classList.add('visible');
  }

  function closeSidebar() {
    $('#sidebar').classList.remove('open');
    $('#sidebarScrim').classList.remove('visible');
  }

  function renderWallet() {
    const balanceEl = $('#walletBalance');
    const balanceText = formatMoney(state.walletBalance);
    if (balanceEl) balanceEl.textContent = balanceText;
    const list = $('#transactionList');
    if (list) {
      list.innerHTML = state.transactions.map((transaction) => `
        <div class="transaction-row">
          <span class="transaction-icon ${transaction.type === 'out' ? 'out' : ''}">${icon(transaction.type === 'out' ? 'arrow-up-right' : 'banknote')}</span>
          <div class="transaction-info"><strong>${escapeHTML(transaction.title)}</strong><span>${escapeHTML(transaction.meta)}</span></div>
          <div class="transaction-amount ${transaction.type === 'out' ? 'out' : ''}">${transaction.type === 'out' ? '-' : '+'}¥${formatMoney(transaction.amount)}<small>${transaction.status || '已确认'}</small></div>
        </div>
      `).join('');
    }
  }

  function updateClockUI() {
    const clockCard = $('.clock-card');
    const display = $('#clockDisplay');
    const status = $('#clockStatusBadge');
    const button = $('#clockButton');
    const earning = $('#clockEarning');
    const hint = $('#clockHint');
    if (!display) return;
    clockCard?.classList.remove('running');
    if (status) status.innerHTML = '<span class="status-dot"></span>未开始';
    if (button) button.innerHTML = `${icon('clock')}开始工作`;
    display.textContent = '00:00:00';
    if (earning) earning.textContent = '¥0.00';
    if (hint) hint.textContent = '开始打卡后自动计算工时';
  }

  function switchMerchantTab(tab) {
    $$('#merchantTabs .tab').forEach((item) => item.classList.toggle('active', item.dataset.merchantTab === tab));
    $$('.merchant-panel').forEach((panel) => panel.classList.toggle('active', panel.id === `merchant-panel-${tab}`));
    if (tab === 'manage') renderMerchantJobs();
  }

  function renderMerchantJobs() {
    const list = $('#merchantJobList');
    if (list) {
      list.innerHTML = state.merchantJobs.map((position) => {
        const statusMap = {
          active: ['检测完成', ''],
          pending: ['检测中', 'pending'],
          closed: ['已归档', 'closed']
        };
        const [statusText, statusClass] = statusMap[position.status] || statusMap.active;
        return `
          <div class="merchant-job-row">
            <div class="merchant-job-info">
              <span class="merchant-logo ${escapeHTML(position.logoClass || 'logo-mstand')}">${escapeHTML(position.logo || 'M')}</span>
              <div><strong>${escapeHTML(position.title)}</strong><span>${escapeHTML(position.meta)}</span></div>
            </div>
            <div class="merchant-job-cell"><strong>${escapeHTML(position.pay)}</strong><span>${escapeHTML(position.settlement)}</span></div>
            <div class="merchant-job-cell"><strong>${position.riskCount || 0} 项</strong><span>风险提示</span></div>
            <div><span class="status-label ${statusClass}">${statusText}</span></div>
            <div class="row-actions">
              <button class="button button-light button-sm" data-toast="示例模式：检测报告暂不展开">查看报告</button>
            </div>
          </div>
        `;
      }).join('');
    }
    const count = $('#manageCount');
    if (count) count.textContent = String(state.merchantJobs.length);
  }

  function renderReliefHistory() {
    const list = $('#reliefHistoryList');
    if (!list) return;
    const history = initialReliefHistory;
    if (!Array.isArray(history) || !history.length) {
      list.innerHTML = '<p style="font-size:9px;color:#9ba59f">暂无申请记录</p>';
      return;
    }
    list.innerHTML = history.slice(0, 3).map((item) => `
      <div class="relief-history-item">
        <strong>${escapeHTML(item.id)} <span>${escapeHTML(item.status)}</span></strong>
        <p>${escapeHTML(item.type)} · ${escapeHTML(item.amount)}</p>
      </div>
    `).join('');
  }

  const riskRules = [
    { key: 'fee', words: ['押金', '保证金', '服装费', '培训费', '平台费', '中介费', '先交', '先付', '垫付', '收费'], penalty: 35, label: '收费风险' },
    { key: 'gray', words: ['刷单', '冲销量', '返利', '高额返利', '代注册', '引流', '点赞赚钱', '跑分'], penalty: 45, label: '违规工作' },
    { key: 'promise', words: ['日入过万', '日入', '轻松月入', '月入过万', '躺赚', '无需经验', '动动手指'], penalty: 15, label: '虚假承诺' },
    { key: 'contact', words: ['加微信', '微信', 'QQ', '私聊', '私下交易'], penalty: 10, label: '私下联系' },
    { key: 'noContract', words: ['不签合同', '无需合同', '不签协议', '口头约定'], penalty: 18, label: '合同风险' },
    { key: 'vagueSalary', words: ['工资面议', '薪资面议', '待遇面议'], penalty: 10, label: '薪资模糊' },
    { key: 'sensitive', words: ['身份证', '银行卡', '验证码', '手持身份证'], penalty: 20, label: '信息风险' }
  ];

  function scanText(text) {
    let score = 100;
    const matched = {};
    const riskWords = new Set();
    riskRules.forEach((rule) => {
      const hits = rule.words.filter((word) => text.includes(word));
      if (hits.length) {
        matched[rule.key] = hits;
        hits.forEach((word) => riskWords.add(word));
        score -= rule.penalty;
      }
    });

    const hasAmount = /(?:¥|￥)?\s*\d+(?:\.\d+)?\s*元\s*(?:\/|每)?\s*(?:天|日|小时|月|条|次)/.test(text);
    const hasSettlement = /(日结|周结|月结|项目结|平台担保|担保结算)/.test(text);
    const hasContract = /(签订|签署|兼职协议|劳动合同|合同)/.test(text);
    const hasContent = /(工作内容|岗位职责|负责|主要工作)/.test(text);
    const hasSubject = /(公司|门店|工作室|企业|品牌|中心|咖啡馆|超市)/.test(text);

    if (!hasAmount) score -= 10;
    if (!hasSettlement) score -= 5;
    if (!hasContent) score -= 8;
    if (!hasContract && !matched.noContract) score -= 8;
    if (!hasSubject) score -= 5;
    score = Math.max(5, Math.min(100, score));

    const checks = [];
    if (matched.sensitive) {
      checks.push({ status: 'fail', name: '主体资质', detail: '岗位文本索取身份证、银行卡等敏感信息，存在身份盗用风险。' });
    } else if (hasSubject) {
      checks.push({ status: 'pass', name: '主体资质', detail: '识别到岗位主体信息，建议仍核验营业执照或门店地址。' });
    } else {
      checks.push({ status: 'warn', name: '主体资质', detail: '未识别到明确的岗位主体，无法确认发布方真实身份。' });
    }

    if (matched.promise || !hasAmount) {
      checks.push({ status: 'fail', name: '薪资规范', detail: matched.promise ? '出现「日入」「无需经验」等夸大承诺，薪资可信度低。' : '未识别到明确的薪资金额与计价单位，存在事后压价风险。' });
    } else if (!hasSettlement) {
      checks.push({ status: 'warn', name: '薪资规范', detail: '薪资金额明确，但未注明结算周期，建议事先确认支付时间。' });
    } else {
      checks.push({ status: 'pass', name: '薪资规范', detail: '薪资金额与结算方式清晰，符合平台信息规范。' });
    }

    if (matched.fee) {
      checks.push({ status: 'fail', name: '收费风险', detail: `检测到「${matched.fee.join('、')}」等收费表述。正规兼职不应向求职者收取任何费用。` });
    } else {
      checks.push({ status: 'pass', name: '收费风险', detail: '未发现押金、培训费、服装费等前置收费表述。' });
    }

    if (matched.gray) {
      checks.push({ status: 'fail', name: '工作内容', detail: '岗位疑似涉及刷单、返利等违规或灰产活动，建议立即停止沟通。' });
    } else if (hasContent) {
      checks.push({ status: 'pass', name: '工作内容', detail: '工作职责描述相对清晰，未发现明显灰产关键词。' });
    } else {
      checks.push({ status: 'warn', name: '工作内容', detail: '工作内容描述较少，建议要求对方补充具体职责与交付标准。' });
    }

    if (matched.contact) {
      checks.push({ status: 'warn', name: '联系规范', detail: '岗位方引导添加私人微信或站外私聊，脱离平台保障后维权难度较高。' });
    } else {
      checks.push({ status: 'pass', name: '联系规范', detail: '未发现明显的站外私下联系引导。' });
    }

    if (matched.noContract || (!hasContract && !matched.noContract)) {
      checks.push({
        status: matched.noContract ? 'fail' : 'warn',
        name: '合同用工',
        detail: matched.noContract ? '明确表示不签订合同，发生欠薪时举证困难。' : '未提及书面协议或合同，建议入职前确认工作约定。'
      });
    } else {
      checks.push({ status: 'pass', name: '合同用工', detail: '文本提及签订协议，建议确认协议中包含薪资与工作时间。' });
    }

    const failCount = checks.filter((check) => check.status === 'fail').length;
    const warnCount = checks.filter((check) => check.status === 'warn').length;
    const passCount = checks.filter((check) => check.status === 'pass').length;

    let level;
    if (score >= 85) {
      level = { label: '合规良好', badge: 'badge-green', color: '#3f7d57', verdict: '可优先考虑', copy: '未发现明显违规特征，仍建议核验商家资质并保留沟通记录。' };
    } else if (score >= 65) {
      level = { label: '基本合规', badge: 'badge-sand', color: '#b5842f', verdict: '谨慎核实后申请', copy: '发现少量不规范表述，建议进一步确认薪资、结算与用工细节。' };
    } else if (score >= 40) {
      level = { label: '中高风险', badge: 'badge-coral', color: '#d26a4c', verdict: '不建议直接申请', copy: '存在多项风险特征，请勿提前付款，并核实商家真实身份。' };
    } else {
      level = { label: '高风险', badge: 'badge-coral', color: '#c5533c', verdict: '强烈建议拒绝', copy: '检测到典型兼职诈骗特征，请立即停止沟通、保留证据并向平台举报。' };
    }

    const advice = [];
    if (matched.fee) advice.push('拒绝任何形式的入职前收费，正规岗位不会向求职者收取押金、服装费或培训费。');
    if (matched.gray) advice.push('刷单、返利、代注册等均可能涉及违法活动，请立即停止沟通并向平台举报。');
    if (matched.contact) advice.push('坚持在平台内沟通与交易，不要添加私人微信或向个人账户转账。');
    if (matched.noContract) advice.push('要求签订书面兼职协议，明确工作内容、薪资标准与结算时间。');
    if (!hasAmount) advice.push('主动询问并按「金额 + 计价单位 + 结算周期」确认薪资，截图留存。');
    if (!advice.length) advice.push('通过平台官方渠道沟通，入职前确认协议内容，并保存聊天、考勤与薪资记录。');
    advice.push('如已发生转账或纠纷，立即在平台发起快捷维权，并拨打 12333 咨询。');

    return {
      score,
      level,
      checks,
      riskWords: Array.from(riskWords),
      failCount,
      warnCount,
      passCount,
      advice: [...new Set(advice)]
    };
  }

  const contractSample = `兼职合作协议
甲方：星启文化传媒有限公司
乙方：马小满

一、乙方入职前需一次性缴纳服装费、培训费共 198 元，工作满 30 天后退还。
二、兼职工资统一于次月 30 日发放，若乙方中途离职，未结算工资不予支付。
三、甲方可根据经营需要随时调整乙方的工作内容和工作时长，乙方应无条件配合。
四、兼职期间如发生意外伤害，由乙方自行承担，甲方不承担任何责任。
五、本协议最终解释权归甲方所有，双方如有争议，以甲方认定为准。`;

  const contractRisks = [
    {
      level: 'high',
      clause: '乙方入职前需一次性缴纳服装费、培训费共 198 元，工作满 30 天后退还。',
      explanation: '这是典型的入职前收费。很多兼职骗局会用“工作满一定天数后退还”诱导先付款，后续常以考核不合格等理由拒绝退款。',
      law: '《劳动合同法》第九条：用人单位招用劳动者，不得要求劳动者提供担保或者以其他名义向劳动者收取财物。',
      advice: '拒绝先行支付任何费用，并要求对方删除该项收费条款。',
      script: '“我可以先确认工作内容和薪资，但入职前不缴纳任何服装费或培训费，我们按正规兼职协议执行。”'
    },
    {
      level: 'high',
      clause: '兼职工资统一于次月 30 日发放，若乙方中途离职，未结算工资不予支付。',
      explanation: '“中途离职不结算”属于变相克扣劳动报酬。即使提前结束兼职，已经完成的工作也应当按约定支付工资。',
      law: '《劳动法》第五十条：工资应当以货币形式按月支付给劳动者本人，不得克扣或者无故拖欠劳动者的工资。',
      advice: '要求改为按实际完成工时结算，并在协议中写明具体结算节点。',
      script: '“如果我只做了一部分，已完成的工时还是需要按约定结算，请把结算方式改成按实际工时计算。”'
    },
    {
      level: 'medium',
      clause: '甲方可根据经营需要随时调整乙方的工作内容和工作时长，乙方应无条件配合。',
      explanation: '“随时调整、无条件配合”会让实际工作内容和时长与最初约定不一致，可能变相增加工作量。',
      law: '《劳动合同法》第三十五条：用人单位与劳动者协商一致，可以变更劳动合同约定的内容。',
      advice: '要求涉及工作内容和时长的调整需双方书面确认，删除“无条件配合”表述。',
      script: '“工作内容或时间如果需要调整，我们可以提前沟通并书面确认，但不太能接受无条件变更。”'
    },
    {
      level: 'high',
      clause: '兼职期间如发生意外伤害，由乙方自行承担，甲方不承担任何责任。',
      explanation: '此类“意外免责”并不能当然免除用工方责任，发生伤害时仍可能涉及赔偿责任，签署前应要求补充安全保障。',
      law: '《民法典》第一千一百九十二条：个人之间形成劳务关系，提供劳务一方因劳务受到损害的，根据双方各自的过错承担相应的责任。',
      advice: '要求明确工作场所安全责任，并确认商家是否购买相关保险。',
      script: '“工作期间的安全保障需要在协议里写清楚，请补充意外险或明确安全责任。”'
    },
    {
      level: 'medium',
      clause: '本协议最终解释权归甲方所有，双方如有争议，以甲方认定为准。',
      explanation: '“最终解释权归甲方”会削弱你的协商和维权空间，格式条款的解释不应由单方决定。',
      law: '《民法典》第四百九十六条：采用格式条款订立合同的，应当遵循公平原则确定当事人之间的权利和义务。',
      advice: '删除单方解释权条款，改为双方协商或依法处理。',
      script: '“这条单方解释的约定不太公平，请改成双方协商解决。”'
    }
  ];

  function runComplianceScan() {
    const input = $('#complianceInput');
    const placeholder = $('#scanPlaceholder');
    const loading = $('#scanLoading');
    const report = $('#scanReport');
    const button = $('#runComplianceScan');
    const text = input?.value.trim() || '';
    if (text.length < 10) {
      showToast('请先粘贴至少 10 个字的合同内容', 'error');
      input?.focus();
      return;
    }

    state.scanTimers.forEach((timer) => clearTimeout(timer));
    state.scanTimers = [];
    placeholder?.classList.add('hidden');
    report?.classList.remove('visible');
    report && (report.innerHTML = '');
    loading?.classList.add('visible');
    if (button) {
      button.disabled = true;
      button.style.opacity = '0.7';
      button.innerHTML = `${icon('shield')}正在分析...`;
    }

    const phases = [
      '扫描收费与押金相关表述...',
      '识别结算、免责与解除条款...',
      '整理风险依据与沟通建议...'
    ];
    phases.forEach((phase, index) => {
      const timer = window.setTimeout(() => {
        const loadingText = $('#scanLoadingText');
        if (loadingText) loadingText.textContent = phase;
      }, 450 * (index + 1));
      state.scanTimers.push(timer);
    });

    const finish = window.setTimeout(() => {
      loading?.classList.remove('visible');
      if (report) {
        report.innerHTML = `
          <div class="contract-report-head">
            <div>
              <p class="eyebrow">CLAUSE RISK LIST</p>
              <h3>合同风险逐条提示</h3>
              <p>以下仅对识别出的条款作风险展示，不对整份合同作安全性判断。</p>
            </div>
            <span class="badge badge-sand">演示样例</span>
          </div>
          <div class="contract-risk-list">
            ${contractRisks.map((risk, index) => `
              <article class="contract-risk-item ${risk.level}">
                <div class="contract-risk-head">
                  <span class="risk-level-pill ${risk.level}"><i></i>${risk.level === 'high' ? '高风险隐患' : '中等风险隐患'}</span>
                  <span class="risk-index">风险 ${String(index + 1).padStart(2, '0')}</span>
                </div>
                <div class="risk-clause-label">原文片段</div>
                <blockquote class="risk-clause">${escapeHTML(risk.clause)}</blockquote>
                <div class="risk-field-grid">
                  <div class="risk-field"><span>大白话解读</span><p>${escapeHTML(risk.explanation)}</p></div>
                  <div class="risk-field"><span>法条提示</span><p>${escapeHTML(risk.law)}</p></div>
                  <div class="risk-field"><span>应对建议</span><p>${escapeHTML(risk.advice)}</p></div>
                  <div class="risk-field script"><span>沟通话术</span><p>${escapeHTML(risk.script)}</p></div>
                </div>
              </article>
            `).join('')}
          </div>
          <div class="report-actions">
            <button class="button button-light" data-rescan>重新检测</button>
            <button class="button button-dark" data-toast="示例模式：可带着合同问题咨询平台顾问">咨询平台顾问</button>
          </div>
          <div class="report-disclaimer">
            <strong>【免责提示】</strong>
            <p>本工具仅识别展示合同风险隐患，仅作参考；不属于法律鉴定意见，不能替代执业律师法律服务；是否签约由学生本人自行判断。</p>
          </div>
        `;
        report.classList.add('visible');
      }
      if (button) {
        button.disabled = false;
        button.style.opacity = '';
        button.innerHTML = `${icon('shield')}开始风险检测`;
      }
      if (window.innerWidth < 700) {
        $('#scanResultCard')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
      }
    }, 1650);
    state.scanTimers.push(finish);
  }

  function validateReliefStep(step) {
    const panel = $(`[data-relief-panel="${step}"]`);
    if (!panel) return true;
    let firstInvalid = null;
    $$('[required]', panel).forEach((field) => {
      field.classList.remove('invalid');
      const empty = field.type === 'checkbox' ? !field.checked : !String(field.value || '').trim();
      if (empty) {
        field.classList.add('invalid');
        if (!firstInvalid) firstInvalid = field;
      }
    });
    if (step === 1) {
      const phone = $('[name="phone"]', panel);
      if (phone && phone.value.replace(/\D/g, '').length < 7) {
        phone.classList.add('invalid');
        if (!firstInvalid) firstInvalid = phone;
      }
    }
    if (step === 2) {
      const amount = $('[name="amount"]', panel);
      if (amount && Number(amount.value) <= 0) {
        amount.classList.add('invalid');
        if (!firstInvalid) firstInvalid = amount;
      }
    }
    if (firstInvalid) {
      showToast('请完善标记为必填的信息', 'error');
      firstInvalid.focus();
      return false;
    }
    return true;
  }

  function setReliefStep(step, scroll = true) {
    state.reliefStep = Math.min(4, Math.max(1, step));
    $$('.relief-step-panel').forEach((panel) => panel.classList.toggle('active', Number(panel.dataset.reliefPanel) === state.reliefStep));
    $$('#reliefStepper .step').forEach((item) => {
      const itemStep = Number(item.dataset.step);
      item.classList.toggle('active', itemStep === state.reliefStep);
      item.classList.toggle('completed', itemStep < state.reliefStep);
    });
    const prev = $('#reliefPrevButton');
    const next = $('#reliefNextButton');
    const submit = $('#reliefSubmitButton');
    if (prev) prev.hidden = state.reliefStep === 1;
    if (next) next.hidden = state.reliefStep === 4;
    if (submit) submit.hidden = state.reliefStep !== 4;
    if (state.reliefStep === 4) fillReliefReview();
    if (scroll) $('#reliefFormCard')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
  }

  function fillReliefReview() {
    const form = $('#reliefForm');
    if (!form) return;
    const data = new FormData(form);
    const review = $('#reliefReview');
    if (!review) return;
    const value = (key, fallback = '未填写') => escapeHTML(data.get(key) || fallback);
    review.innerHTML = `
      <div class="review-item"><span>申请人</span><strong>${value('name')}</strong></div>
      <div class="review-item"><span>就读院校</span><strong>${value('school')}</strong></div>
      <div class="review-item"><span>联系电话</span><strong>${value('phone')}</strong></div>
      <div class="review-item"><span>被骗类型</span><strong>${value('fraudType')}</strong></div>
      <div class="review-item"><span>涉事商家</span><strong>${value('merchant')}</strong></div>
      <div class="review-item"><span>被骗金额</span><strong>¥${formatMoney(data.get('amount'))}</strong></div>
      <div class="review-item"><span>被骗日期</span><strong>${value('date')}</strong></div>
      <div class="review-item"><span>支付方式</span><strong>${value('payment')}</strong></div>
      <div class="review-item"><span>报警情况</span><strong>${value('police')}</strong></div>
      <div class="review-item"><span>学生身份</span><strong>${value('identity')}</strong></div>
      <div class="review-item full"><span>事件经过</span><strong>${value('detail')}</strong></div>
    `;
  }

  function attachUploadPreview(input, list) {
    if (!input || !list) return;
    input.addEventListener('change', () => {
      const files = Array.from(input.files || []);
      list.innerHTML = files.map((file) => `<span class="file-chip">${icon('file')}${escapeHTML(file.name)}</span>`).join('');
    });
    const zone = input.closest('.upload-zone');
    if (zone) {
      ['dragenter', 'dragover'].forEach((eventName) => zone.addEventListener(eventName, (event) => {
        event.preventDefault();
        zone.classList.add('dragover');
      }));
      ['dragleave', 'drop'].forEach((eventName) => zone.addEventListener(eventName, (event) => {
        event.preventDefault();
        zone.classList.remove('dragover');
      }));
      zone.addEventListener('drop', (event) => {
        const files = event.dataTransfer?.files;
        if (!files || !files.length) return;
        try {
          const transfer = new DataTransfer();
          Array.from(files).forEach((file) => transfer.items.add(file));
          input.files = transfer.files;
          input.dispatchEvent(new Event('change'));
        } catch (error) {
          list.innerHTML = Array.from(files).map((file) => `<span class="file-chip">${icon('file')}${escapeHTML(file.name)}</span>`).join('');
        }
      });
    }
  }

  function wireEvents() {
    document.addEventListener('submit', (event) => {
      if (event.target.id === 'heroSearchForm') return;
      event.preventDefault();
      event.stopPropagation();
      returnHome();
    }, true);

    document.addEventListener('click', (event) => {
      const jobCard = event.target.closest('.job-card');
      if (jobCard) {
        openJobModal(jobCard.dataset.jobId);
        return;
      }

      const pageTrigger = event.target.closest('[data-page]');
      if (pageTrigger) {
        event.preventDefault();
        $$('.modal-backdrop.open').forEach((modal) => {
          if (modal.id !== 'complianceGate') closeModal(modal.id);
        });
        navigate(pageTrigger.dataset.page);
        if (pageTrigger.dataset.toast) showToast(pageTrigger.dataset.toast, 'info');
        return;
      }

      const closeTrigger = event.target.closest('[data-close-modal]');
      if (closeTrigger) {
        closeModal(closeTrigger.dataset.closeModal);
        return;
      }

      if (event.target.classList.contains('modal-backdrop')) {
        if (event.target.dataset.locked === 'true') return;
        closeModal(event.target.id);
        return;
      }

      const merchantTab = event.target.closest('[data-merchant-tab]');
      if (merchantTab) {
        switchMerchantTab(merchantTab.dataset.merchantTab);
        return;
      }

      const accordion = event.target.closest('.accordion-trigger');
      if (accordion) {
        const expanded = accordion.getAttribute('aria-expanded') === 'true';
        const content = accordion.nextElementSibling;
        $$('.accordion-trigger').forEach((trigger) => {
          if (trigger !== accordion) {
            trigger.setAttribute('aria-expanded', 'false');
            trigger.nextElementSibling?.classList.remove('open');
          }
        });
        accordion.setAttribute('aria-expanded', String(!expanded));
        content?.classList.toggle('open', !expanded);
        return;
      }

      const sample = event.target.closest('[data-sample]');
      if (sample) {
        const input = $('#complianceInput');
        if (input) {
          input.value = contractSample;
          input.dispatchEvent(new Event('input'));
          input.focus();
        }
        return;
      }

      if (event.target.closest('[data-rescan]')) {
        runComplianceScan();
        return;
      }

      if (event.target.closest('[data-scan-rights]')) {
        navigate('rights');
        window.setTimeout(() => {
          const detail = $('#rightsForm [name="detail"]');
          const input = $('#complianceInput');
          if (detail && input?.value) detail.value = `我看到一条疑似违规的岗位信息，希望平台核实：\n${input.value.slice(0, 500)}`;
        }, 120);
        showToast('已带你进入维权申请，请补充联系方式', 'info');
        return;
      }

      const toastTrigger = event.target.closest('[data-toast]');
      if (toastTrigger) {
        showToast(toastTrigger.dataset.toast, 'info');
        return;
      }

      const channel = event.target.closest('.channel-card');
      if (channel) {
        showToast('服务入口已接入，演示版本可继续使用下方表单', 'info');
        return;
      }

      if (!event.target.closest('.notification-wrap')) {
        $('#notificationPopover')?.classList.remove('open');
      }
    });

    document.addEventListener('keydown', (event) => {
      if (event.key === 'Escape') {
        $$('.modal-backdrop.open').forEach((modal) => {
          if (modal.dataset.locked !== 'true') closeModal(modal.id);
        });
        closeSidebar();
        $('#notificationPopover')?.classList.remove('open');
      }
      if ((event.key === 'Enter' || event.key === ' ') && event.target.classList.contains('job-card')) {
        event.preventDefault();
        openJobModal(event.target.dataset.jobId);
      }
    });

    document.addEventListener('input', (event) => {
      if (event.target.matches('input, select, textarea')) {
        event.target.classList.remove('invalid');
      }
    });

    $('#sidebarScrim')?.addEventListener('click', closeSidebar);
    $('#menuButton')?.addEventListener('click', openSidebar);

    window.addEventListener('hashchange', () => {
      activatePage(location.hash.replace('#', '') || 'dashboard');
    });

    $('#notificationButton')?.addEventListener('click', (event) => {
      event.stopPropagation();
      $('#notificationPopover')?.classList.toggle('open');
    });

    $('#markRead')?.addEventListener('click', () => {
      $('.notification-dot')?.remove();
      $('#notificationPopover')?.classList.remove('open');
      showToast('所有消息已标记为已读');
    });

    $('#acceptComplianceGate')?.addEventListener('click', () => {
      closeModal('complianceGate');
      window.setTimeout(() => $('#complianceInput')?.focus(), 120);
    });

    $('#heroSearchForm')?.addEventListener('submit', (event) => {
      event.preventDefault();
      setJobSearch($('#heroSearchInput')?.value || '');
    });

    $$('[data-search-keyword]').forEach((button) => {
      button.addEventListener('click', () => setJobSearch(button.dataset.searchKeyword));
    });

    $('#jobSearchInput')?.addEventListener('input', (event) => {
      state.search = event.target.value;
      renderJobGrids();
    });

    $('#jobLocationFilter')?.addEventListener('change', (event) => {
      state.location = event.target.value;
      renderJobGrids();
    });

    $('#jobSortFilter')?.addEventListener('change', (event) => {
      state.sort = event.target.value;
      renderJobGrids();
    });

    $('#jobCategoryFilters')?.addEventListener('click', (event) => {
      const chip = event.target.closest('[data-category]');
      if (!chip) return;
      state.category = chip.dataset.category;
      $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item === chip));
      renderJobGrids();
    });

    $('#resetJobFilters')?.addEventListener('click', () => {
      state.category = '全部';
      state.search = '';
      state.location = 'all';
      state.sort = 'recommend';
      if ($('#jobSearchInput')) $('#jobSearchInput').value = '';
      if ($('#jobLocationFilter')) $('#jobLocationFilter').value = 'all';
      if ($('#jobSortFilter')) $('#jobSortFilter').value = 'recommend';
      $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item.dataset.category === '全部'));
      renderJobGrids();
    });

    $('#complianceInput')?.addEventListener('input', (event) => {
      const count = $('#scanCharCount');
      if (count) count.textContent = String(event.target.value.length);
    });
    $('#runComplianceScan')?.addEventListener('click', runComplianceScan);
    $('#clearCompliance')?.addEventListener('click', () => {
      const input = $('#complianceInput');
      if (input) {
        input.value = '';
        input.dispatchEvent(new Event('input'));
        input.focus();
      }
      $('#scanPlaceholder')?.classList.remove('hidden');
      $('#scanLoading')?.classList.remove('visible');
      $('#scanReport')?.classList.remove('visible');
    });

    attachUploadPreview($('#rightsFiles'), $('#rightsFileList'));
    attachUploadPreview($('#reliefFiles'), $('#reliefFileList'));

    $('#reliefNextButton')?.addEventListener('click', () => {
      if (!validateReliefStep(state.reliefStep)) return;
      setReliefStep(state.reliefStep + 1);
    });
    $('#reliefPrevButton')?.addEventListener('click', () => setReliefStep(state.reliefStep - 1));

    $('#copyReliefCase')?.addEventListener('click', async () => {
      const caseNumber = $('#reliefCaseNumber')?.textContent || '';
      try {
        await navigator.clipboard.writeText(caseNumber);
        showToast('申请编号已复制');
      } catch (error) {
        showToast(`申请编号：${caseNumber}`, 'info');
      }
    });

    $('#newReliefButton')?.addEventListener('click', () => navigate('dashboard'));
  }

  function setJobSearch(keyword) {
    state.search = keyword;
    state.category = '全部';
    const search = $('#jobSearchInput');
    if (search) search.value = keyword;
    $$('#jobCategoryFilters .chip').forEach((item) => item.classList.toggle('active', item.dataset.category === '全部'));
    renderJobGrids();
    navigate('jobs');
  }

  function init() {
    wireEvents();
    renderJobGrids();
    const navBadge = $('#jobsNavBadge');
    if (navBadge) navBadge.textContent = String(jobs.length);
    renderMerchantJobs();
    renderWallet();
    updateClockUI();
    renderReliefHistory();

    const initialPage = location.hash.replace('#', '') || 'dashboard';
    if (!location.hash) {
      history.replaceState(null, '', '#dashboard');
    }
    activatePage(initialPage);
    setReliefStep(1, false);
    if ($('#complianceInput')) $('#scanCharCount').textContent = String($('#complianceInput').value.length);
  }

  init();
})();
