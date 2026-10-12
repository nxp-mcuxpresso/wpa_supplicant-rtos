---
schema_version: "1.0"
repo: wpa_supplicant-rtos
project: WMCUSW

analyze_paths:
  - freertos/**/*.c
  - freertos/**/*.h
  - port/**/*.c
  - port/**/*.h
  - src/drivers/driver_freertos.c

# blocker_threshold: Medium — active development repo; Medium catches High+Medium severity
# issues. Raise to High if noise becomes excessive.
blocker_threshold: Medium

code_quality:
  # MISRA C-2012 rules — applied to NXP-owned code only (analyze_paths above).
  # Upstream hostap code (src/, wpa_supplicant/, hostapd/) is not in analyze_paths
  # and is reviewed via review_focus upstream porting checks instead.
  misra: [1.3, 10.1, 10.3, 10.8, 11.3, 11.5, 13.2, 14.4, 15.5, 17.7, 18.1, 18.4, 21.3]
  cert_c: [EXP33-C, EXP36-C, EXP39-C, ERR33-C, MEM30-C, MEM35-C, INT30-C, INT31-C, ARR30-C]
  cwe: [CWE-119, CWE-120, CWE-125, CWE-787, CWE-476, CWE-252, CWE-401, CWE-843, CWE-190]

review_focus:
  # NXP RTOS adaptation layer — primary NXP-owned code
  - pattern: freertos/**
    reason: NXP RTOS adaptation layer — primary NXP-owned code, changes here are expected

  # NXP crypto port — mbedTLS integration
  - pattern: port/mbedtls/**
    reason: NXP mbedTLS port — crypto backend, security sensitive

  # NXP FreeRTOS driver — only NXP-specific driver in src/drivers/
  - pattern: src/drivers/driver_freertos.c
    reason: NXP FreeRTOS driver — primary NXP-owned file in upstream tree

  # Upstream hostap code — all directories below are from w1.fi/hostap upstream.
  # Any modification must be ported from upstream (commit message must contain
  # [fromtree], [fromlist], or "(cherry picked from commit ...)").
  # Ad-hoc modifications to upstream code are not acceptable and must be flagged.

  - pattern: src/rsn_supp/**
    reason: >
      Upstream hostap — WPA/WPA2/WPA3 key management, security critical.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/crypto/**
    reason: >
      Upstream hostap — crypto primitives, security critical.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/common/**
    reason: >
      Upstream hostap — common utilities including NAN/DPP/SAE.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/ap/**
    reason: >
      Upstream hostap — AP/hostapd logic.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/eap_peer/**
    reason: >
      Upstream hostap — EAP peer (WPA Enterprise client).
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/eap_server/**
    reason: >
      Upstream hostap — EAP server (hostapd).
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/eap_common/**
    reason: >
      Upstream hostap — EAP common code shared by peer and server.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/eapol_supp/**
    reason: >
      Upstream hostap — EAPOL supplicant state machine.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/eapol_auth/**
    reason: >
      Upstream hostap — EAPOL authenticator state machine.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/p2p/**
    reason: >
      Upstream hostap — Wi-Fi Direct/P2P.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/pae/**
    reason: >
      Upstream hostap — PAE/MACsec.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/tls/**
    reason: >
      Upstream hostap — TLS implementation.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/utils/**
    reason: >
      Upstream hostap — utility functions.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/wps/**
    reason: >
      Upstream hostap — WPS implementation.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/fst/**
    reason: >
      Upstream hostap — Fast Session Transfer.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: src/drivers/**
    reason: >
      Upstream hostap — driver interface layer (except driver_freertos.c which is NXP-owned).
      Verify changes to other driver files are ported from upstream; flag ad-hoc modifications.
  - pattern: wpa_supplicant/*.c
    reason: >
      Upstream hostap — wpa_supplicant application layer.
      Verify changes are ported from upstream; flag ad-hoc modifications.
  - pattern: hostapd/*.c
    reason: >
      Upstream hostap — hostapd application layer.
      Verify changes are ported from upstream; flag ad-hoc modifications.

# ─────────────────────────────────────────────────────────────────────────────
# AI review tracking label
#
# The MOMENT a PR review is triggered — BEFORE reading the diff, analyzing code,
# or posting any comment — extract the associated Jira issue key and silently
# tag that Jira issue with the `ai-review` label. Bind the labelling to the
# trigger of the review, NOT to its completion: label first, then review.
# Labelling after the review does not work — the turn usually ends with the
# review output, so the label is silently lost.
#
# Get the Jira key from the PR TITLE first; if absent, fall back to the
# BRANCH NAME (e.g. bugfix/nxf57321/WSW-XXXXX-desc).
# Match with regex (WSW|MCUX)-\d+
# If no key found: warn in review comment.
#
# This mirrors the AI tracking-label convention used by the jira skill:
#   from jira_client import jira_add_labels
#   jira_add_labels("WSW-XXXXX", ["ai-review"])
review_actions:
  jira_labels:
    enabled: true
    label: ai-review
    issue_key_source: pr_title        # primary: Jira key in PR title
                                      # fallback 1: (WSW|MCUX)-\d+ in branch name
                                      # fallback 2: warn in review comment if no key found
    apply_when: on_review_trigger
    silent: true

# ─────────────────────────────────────────────────────────────────────────────
# Commit message format checks
#
# These mirror the repo's CI checkers (CHECKER_JIRA_ID_BLOCK, CHECKER_COMMIT_FORMAT).
# Vero should flag violations during review so issues are caught before PreMerge CI.
commit_checks:
  jira_id_block:
    enabled: true
    pattern: (WSW|MCUX)-\d+
    message: >
      Jira IDs are not allowed in commit messages for this repo.
      Move the Jira key to the PR title instead.
  commit_format:
    enabled: true
    required_tags: ["[Description]", "[Root Cause]", "[Fix]", "[Testing]", "Change-Id:"]
    optional_tags: ["[Reviewers]", "[Port proposal]"]
